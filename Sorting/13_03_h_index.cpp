#include <iostream>
#include <algorithm>

using namespace std;

int HIndex(vector<int> citations) {
    sort(begin(citations), end(citations));
    const int n = citations.size();
    for(int i = 0; i < citations.size(); ++i) {
        if(citations[i] >= n - i) {
            return n - i;
        }
    }
    return 0;
}

int main() {
    vector<int> example = {1,4,1,4,2,1,3,5,6};
    int result = HIndex(example);
    cout << result << endl;
}