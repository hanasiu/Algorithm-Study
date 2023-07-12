#include <iostream>
#include <unordered_set>

using namespace std;

int LongestContainedRange(const vector<int>& A) {
    unordered_set<int> unprocessed_entries(A.begin(), A.end());

    int max_interval_size = 0;
    while(!unprocessed_entries.empty()) {
        int a = *unprocessed_entries.begin();
        unprocessed_entries.erase(a);

        int lower_bound = a-1;
        while(unprocessed_entries.count(lower_bound)) {
            unprocessed_entries.erase(lower_bound);
            --lower_bound;
        }

        int upper_bound = a + 1;
        while(unprocessed_entries.count(upper_bound)) {
            unprocessed_entries.erase(upper_bound);
            ++upper_bound;
        }

        max_interval_size = max(max_interval_size, upper_bound - lower_bound -1);
    }
    return max_interval_size;
}

int main() {
    vector<int> i = {10,5,3,11,6,100,4};
    int result = LongestContainedRange(i);
    cout << result << endl;
    return 0;
}