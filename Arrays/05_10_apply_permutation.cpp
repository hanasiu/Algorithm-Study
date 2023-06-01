#include <iostream>
#include <vector>

using namespace std;

void ApplyPermutation(vector<int> perm, vector<int>* A_ptr) {
    vector<int>& A = *A_ptr;
    for(int i = 0; i< A.size(); ++i) {
        while(perm[i] != i) {
            swap(A[i], A[perm[i]]);
            swap(perm[i], perm[perm[i]]);
        }
    }
}

int main() {
    vector<int> i = {1,2,3,4,5};
    vector<int> perm = {2,0,1,4,3};
    ApplyPermutation(perm, &i);
    for(auto k : i){
        cout << k << " ";
    }
    cout << endl;

    return 0;
}