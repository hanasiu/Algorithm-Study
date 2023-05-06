#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GetMaxTrappedWater(const vector<int>& heights) {
    int i = 0, j = heights.size() - 1, max_water = 0;
    while(i<j) {
        int width = j - i;
        max_water = max(max_water, width * min(heights[i], heights[j]));
        if(heights[i] > heights[j]) {
            --j;
        } else {
            ++i;
        }
    }
    return max_water;
}

int main() {
    vector<int> i = {1,2,1,3,4,4,5,6,2,1,3,1,3,2,1,2,4,1};
    int result = GetMaxTrappedWater(i);
    cout << result << endl;
    return 0;
}