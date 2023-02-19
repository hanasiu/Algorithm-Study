#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

double MyHypot(double x, double y, double z) {
    return std::sqrt(x*x + y*y + z*z);
}

struct Star
{
    bool operator<(const Star& that) const
    {
        return Distance() < that.Distance();
    }

    double Distance() const { return MyHypot(x, y, z); }
    double x, y, z;
};


vector<Star> FindClosestKStars(vector<Star>::const_iterator stars_begin,
const vector<Star>::const_iterator& stars_end,
int k) {
    priority_queue<Star> max_heap;
    while(stars_begin != stars_end) {
        max_heap.emplace(*stars_begin++);
        if(max_heap.size() == k+1) {
            max_heap.pop();
        }
    }

    vector<Star> closest_stars;
    while(!max_heap.empty()) {
        closest_stars.emplace_back(max_heap.top());
        max_heap.pop();
    }
    return {rbegin(closest_stars), rend(closest_stars)};
}  

int main() {
    // Seed the random number generator
    srand(time(nullptr));

    // Generate 100 random stars
    vector<Star> stars(100);
    for (int i = 0; i < 100; i++) {
        stars[i].x = (double)rand() / RAND_MAX * 100;
        stars[i].y = (double)rand() / RAND_MAX * 100;
        stars[i].z = (double)rand() / RAND_MAX * 100;
    }

    // Find the 10 closest stars
    vector<Star> closest_stars = FindClosestKStars(stars.begin(), stars.end(), 10);

    // Print the closest stars
    cout << "The " << closest_stars.size() << " closest stars are:\n";
    for (const auto& star : closest_stars) {
        cout << "(" << star.x << ", " << star.y << ", " << star.z << ") - distance: " << star.Distance() << "\n";
    }

    return 0;
}