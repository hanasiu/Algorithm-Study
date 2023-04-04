#include <iostream>
#include <vector>

using namespace std;

string MajoritySearch(vector<string>::const_iterator stream_begin,
const vector<string>::const_iterator stream_end) {
    string candidate;
    int candidate_count = 0;
    while (stream_begin != stream_end) {
        string it = *stream_begin++;
        if(candidate_count == 0) {
            candidate = it;
            candidate_count = 1;
        } else if (candidate == it) {
            ++candidate_count;
        } else {
            --candidate_count;
        }
    }
    return candidate;
}

int main() {
    vector<string> i = {"b","a","c","a","a","b","a","a","c","a"};
    string result = MajoritySearch(i.begin(), i.end());
    cout << result << endl;
    return 0;
}