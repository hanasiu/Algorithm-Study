#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

struct DuplicateAndMissing {
    int duplicate, missing;
};

DuplicateAndMissing FindDuplicateMissing(const vector<int>& A) {
    int miss_XOR_dup = 0;
    for(int i = 0; i< A.size(); ++i) {
        miss_XOR_dup ^= i ^ A[i];
    }

    int differ_bit = miss_XOR_dup & (~(miss_XOR_dup -1));
    int miss_or_dup = 0;
    for(int i = 0; i<A.size(); ++i) {
        if(i&differ_bit) {
            miss_or_dup ^= i;
        }
        if(A[i] & differ_bit) {
            miss_or_dup ^= A[i];
        }
    }
    if(find(A.begin(), A.end(), miss_or_dup) != A.end()) {
        return {miss_or_dup, miss_or_dup ^ miss_XOR_dup};
    }

    return {miss_or_dup ^ miss_XOR_dup, miss_or_dup};
}

int main() {
    vector<int> i = {5,3,0,3,1,2};
    DuplicateAndMissing k = FindDuplicateMissing(i);
    cout << k.duplicate << " " << k.missing << endl;
    return 0;
}