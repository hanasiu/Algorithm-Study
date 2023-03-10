#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <cassert>

using namespace std;

bool HasDuplicate(const vector<vector<int>>& partial_assignment,
int start_row, int end_row, int start_col, int end_col) {
    deque<bool> is_present(partial_assignment.size()+1, false);
    for(int i = start_row; i < end_row; ++i) {
        for(int j = start_col; j<end_col; ++j) {
            if(partial_assignment[i][j] != 0 &&
            is_present[partial_assignment[i][j]]) {
            return true;
            }
            is_present[partial_assignment[i][j]] = true;
        }
    }
    return false;
}

bool IsValidSudoku(const vector<vector<int>>& partial_assignment) {
    for(int i = 0; i < partial_assignment.size(); ++i) {
        if(HasDuplicate(partial_assignment, i, i+1, 0, partial_assignment.size())) {
            return false;
        }
    }

    for(int j = 0; j<partial_assignment.size(); ++j) {
        if(HasDuplicate(partial_assignment, 0, partial_assignment.size(), j, j+1)) {
            return false;
        }
    }

    int region_size = sqrt(partial_assignment.size());
    for(int I = 0; I < region_size; ++I) {
        for(int J = 0; J<region_size; ++J) {
            if(HasDuplicate(partial_assignment, region_size * I,
            region_size*(I+1), region_size*J,
            region_size*(J+1))) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> sudoku = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                                  {6, 0, 0, 1, 9, 5, 0, 0, 0},
                                  {0, 9, 8, 0, 0, 0, 0, 6, 0},
                                  {8, 0, 0, 0, 6, 0, 0, 0, 3},
                                  {4, 0, 0, 8, 0, 3, 0, 0, 1},
                                  {7, 0, 0, 0, 2, 0, 0, 0, 6},
                                  {0, 6, 0, 0, 0, 0, 2, 8, 0},
                                  {0, 0, 0, 4, 1, 9, 0, 0, 5},
                                  {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    assert(IsValidSudoku(sudoku) == true);

    sudoku[0][0] = 3;
    assert(IsValidSudoku(sudoku) == false);

    sudoku[0][0] = 5;
    sudoku[1][0] = 5;
    assert(IsValidSudoku(sudoku) == false);

    cout << "All tests passed!" << endl;

    return 0;
}