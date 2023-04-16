#include <iostream>
#include <vector>
#include "BST.h"

using namespace std;


BstNode* BuildMinHeightBSTFromSortedSubarray
(const vector<int>&A, int start, int end) {
    if(start >= end) {
        return nullptr;
    }
    int mid = start + ((end - start) /2);
    BstNode* root = new BstNode(A[mid]);
    root->left = BuildMinHeightBSTFromSortedSubarray(A, start, mid);
    root->right = BuildMinHeightBSTFromSortedSubarray(A, mid + 1, end);
    return root;
}

BstNode* BuildMindHeightBSTFromSortedArray(
    const vector<int>& A
) {
    return BuildMinHeightBSTFromSortedSubarray(A, 0, A.size());
}

int main() {
    vector<int> i = {2,3,5,7,11,13,17,19,23};
    BstNode* k = BuildMindHeightBSTFromSortedArray(i);
    PrintBstInorder(k);
    return 0;
}
