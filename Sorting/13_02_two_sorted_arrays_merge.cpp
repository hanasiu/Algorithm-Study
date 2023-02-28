#include <iostream>
#include <vector>

using namespace std;

void MergeTwoSortedArrays(vector<int> &A, int m, const vector<int> &B, int n)
{
    int a = m - 1, b = n - 1, write_idx = m + n - 1;
    while (a >= 0 && b >= 0)
    {
        A[write_idx--] = A[a] > B[b] ? A[a--] : B[b--];
    }
    while (b >= 0)
    {
        A[write_idx--] = B[b--];
    }
}

int main()
{
    vector<int> A = {1, 3, 5, 7, 0, 0, 0}; // m = 4
    vector<int> B = {2, 4, 6}; // n = 3
    int m = 4, n = 3;

    MergeTwoSortedArrays(A, m, B, n);

    for (int i = 0; i < m + n; i++)
    {
        cout << A[i] << " ";
    }
    // Output should be: 1 2 3 4 5 6 7

    return 0;
}