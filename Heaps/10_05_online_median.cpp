#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<double> OnlineMedian(vector<int>::const_iterator sequence_begin,
const vector<int>::const_iterator& sequence_end) {
    priority_queue<int, vector<int>, greater<>> min_heap;
    priority_queue<int, vector<int>, less<>> max_heap;
    vector<double> result;

    while(sequence_begin!=sequence_end) {
        min_heap.emplace(*sequence_begin++);
        max_heap.emplace(min_heap.top());
        min_heap.pop();

        if(max_heap.size() > min_heap.size()) {
            min_heap.emplace(max_heap.top());
            max_heap.pop();
        }

        result.emplace_back(min_heap.size() == max_heap.size() 
        ? 0.5 * (min_heap.top() +max_heap.top()) 
        : min_heap.top());
    }
    return result;
}

int main() {
    vector<int> i = {1,0,3,5,2,0,1};
    vector<double> k = OnlineMedian(i.begin(), i.end());
    for(auto j : k) {
        cout << j << " ";
    }
    cout << endl;
    return 0;
}