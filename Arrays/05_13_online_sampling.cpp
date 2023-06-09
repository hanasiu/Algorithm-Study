#include <iostream>
#include <vector>
#include <random>

using namespace std;

vector<int> OnlineRandomSample(vector<int>::const_iterator stream_begin,
const vector<int>::const_iterator stream_end, int k) {
    vector<int> running_sample;
    for(int i = 0; i<k; ++i) {
        running_sample.emplace_back(*stream_begin++);
    }

    default_random_engine seed((random_device())());

    int num_seen_so_far = k;
    while(stream_begin != stream_end) {
        int x = *stream_begin++;
        ++num_seen_so_far;
        const int idx_to_replace = uniform_int_distribution<int>{0,num_seen_so_far-1}(seed);
        if(idx_to_replace < k) {
            running_sample[idx_to_replace] = x;
        }
    }
    return running_sample;
}

int main() {
    vector<int> i = { 1, 4, 5, 100, 200, 300};
    vector<int> example = OnlineRandomSample(i.begin(), i.end(), 3);
    for(auto k : example) {
        cout << k << " ";
    }
    cout << endl;
    return 0;
}