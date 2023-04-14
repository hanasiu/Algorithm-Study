#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int kEmptyEntry = 0;

bool ValidToAddVal(const vector<vector<int>> &partial_assignment, int i,
                   int j, int val)
{
    if (any_of(partial_assignment.begin(), partial_assignment.end(),
               [val, j](const vector<int> &row)
               { return val == row[j]; }))
    {
        return false;
    }

    if (find(partial_assignment[i].begin(), partial_assignment[i].end(), val) !=
        partial_assignment[i].end())
    {
        return false;
    }

    int region_size = sqrt(partial_assignment.size());
    int I = i / region_size, J = j / region_size;
    for (int a = 0; a < region_size; ++a)
    {
        for (int b = 0; b < region_size; ++b)
        {
            if (val == partial_assignment[region_size * I + a][region_size * J + b])
            {
                return false;
            }
        }
    }
    return true;
}

bool SolvePartialSudoku(int i, int j, vector<vector<int>> *partial_assignment)
{
    if (i == (*partial_assignment).size())
    {
        i = 0;
        if (++j == (*partial_assignment)[i].size())
        {
            return true;
        }
    }

    if ((*partial_assignment)[i][j] != kEmptyEntry)
    {
        return SolvePartialSudoku(i + 1, j, partial_assignment);
    }

    for (int val = 1; val <= (*partial_assignment).size(); ++val)
    {
        if (ValidToAddVal(*partial_assignment, i, j, val))
        {
            (*partial_assignment)[i][j] = val;
            if (SolvePartialSudoku(i + 1, j, partial_assignment))
            {
                return true;
            }
        }
    }

    (*partial_assignment)[i][j] = kEmptyEntry;
    return false;
}

bool SolveSudoku(vector<vector<int>> *partial_assignment)
{
    return SolvePartialSudoku(0, 0, partial_assignment);
}

int main()
{
    vector<vector<int>> i = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                             {6, 0, 0, 1, 9, 5, 0, 0, 0},
                             {0, 9, 8, 0, 0, 0, 0, 6, 0},
                             {8, 0, 0, 0, 6, 0, 0, 0, 3},
                             {4, 0, 0, 8, 0, 3, 0, 0, 1},
                             {7, 0, 0, 0, 2, 0, 0, 0, 6},
                             {0, 6, 0, 0, 0, 0, 2, 8, 0},
                             {0, 0, 0, 4, 1, 9, 0, 0, 5},
                             {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    cout << SolveSudoku(&i) << endl;
    for (auto j : i)
    {
        for (auto k : j)
        {
            cout << k << " ";
        }
        cout << endl;
    }
    return 0;
}