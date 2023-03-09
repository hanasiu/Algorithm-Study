#include <iostream>
#include <vector>

using namespace std;

//typedef enum { kRed, KWhite, KBlue } Color;

void DutchFlagPartition(int pivot_index, vector<int>* A_ptr) {
    vector<int>& A = *A_ptr;
    int pivot = A[pivot_index];
    int smaller = 0, equal = 0, larger = A.size();
    while(equal < larger) {
        if(A[equal] < pivot) {
            swap(A[smaller++], A[equal++]);
        } else if (A[equal] == pivot) {
            ++equal;
        } else { // A[equal] > pivot
         swap(A[equal], A[--larger]);
        } 
    }
}

int main() {
    vector<int> A = {-3, 0, -1, -5, 1, 1, 4, 2, 111, 32, 1, 5, 2};
    DutchFlagPartition(5, &A);
    for(auto i : A) {
        cout << i << " ";
    }
    return 0;
}