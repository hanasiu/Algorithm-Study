#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <iostream>

using namespace std;

int ComputeDistanceBetweenPrefixes(
    const string &A, int A_idx, const string &B, int B_idx,
    vector<vector<int>> *distance_between_prefixes_ptr) {
    vector<vector<int>>& distance_between_prefixes = 
    *distance_between_prefixes_ptr;
    if(A_idx<0) {
        return B_idx+1;
    } else if (B_idx<0) {
        return A_idx+1;
    }
    if(distance_between_prefixes[A_idx][B_idx] == -1) {
        if(A[A_idx] == B[B_idx]) {
            distance_between_prefixes[A_idx][B_idx] =
            ComputeDistanceBetweenPrefixes(A, A_idx - 1, B, B_idx - 1,
          distance_between_prefixes_ptr);
        } else {
          int substitute_last = ComputeDistanceBetweenPrefixes(A, A_idx - 1, B, B_idx - 1,
          distance_between_prefixes_ptr);
          int add_last = ComputeDistanceBetweenPrefixes(A, A_idx - 1, B, B_idx,
          distance_between_prefixes_ptr);
          int delete_last = ComputeDistanceBetweenPrefixes(A, A_idx, B, B_idx - 1,
          distance_between_prefixes_ptr);
          distance_between_prefixes[A_idx][B_idx] = 
          1 + min({substitute_last, add_last, delete_last});
        }
    }
    return distance_between_prefixes[A_idx][B_idx];
}

int LevenshteinDistance(const string& A, const string& B) {
    //vector<vector<int>> distance_between_prefixes(A.size(), vector<int>(B.size(), -1));
    return ComputeDistanceBetweenPrefixes(A, A.size() -1, B, B.size() -1,
    make_unique<vector<vector<int>>>(A.size(), vector<int>(B.size(), -1)).get());
}

int main() {
    string str1 = "kit";
    string str2 = "sitting";
    cout << "Levenshtein distance between " << str1 << " and " << str2 << " is ";
    cout << LevenshteinDistance(str1, str2) << endl;

    string str3 = "hello";
    string str4 = "world";
    cout << "Levenshtein distance between " << str3 << " and " << str4 << " is ";
    cout << LevenshteinDistance(str3, str4) << endl;

    return 0;
}