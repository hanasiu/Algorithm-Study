#include <iostream>
#include <vector> 

using namespace std;

int SearchSmallest(const vector<int>& A){
    int left = 0, right = size(A) -1;
    while(left<right) {
        if(int mid = left + ((right - left)/2); A[mid] > A[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    vector<int> i = {378, 478, 550, 631, 103, 203, 220, 234, 279, 368};
    int result = SearchSmallest(i);
    cout << result;
}