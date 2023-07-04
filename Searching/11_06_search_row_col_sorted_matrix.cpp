#include <iostream>

using namespace std;

bool MatrixSearch(const vector<vector<int>> &A, int x)
{
    int row = 0, col = A[0].size() - 1;
    while (row < A.size() && col >= 0)
    {
        //cout << A[row][col] << endl;
        if (A[row][col] == x)
        {
            return true;
        }
        else if (A[row][col] < x)
        {
            ++row;
        }
        else
        {
            --col;
        }
    }
    return false;
}

int main()
{
    const vector<vector<int>> i = {{-1, 2, 4, 4, 6},
                                   {1, 5, 5, 9, 21},
                                   {3, 6, 6, 9, 22},
                                   {3, 6, 8, 10, 24},
                                   {6, 8, 9, 12, 25},
                                   {8, 10, 12, 13, 40}};
    cout << MatrixSearch(i, 8);
    cout << endl;
    cout << MatrixSearch(i, 7);
    return 0;
}