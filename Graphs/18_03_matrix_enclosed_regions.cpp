#include <vector>
#include <deque>
#include <iostream>
#include <queue>

using namespace std;

void MarkBoundaryRegion(int i, int j, vector<vector<char>> *board_ptr)
{
    queue<pair<int, int>> q(deque<pair<int, int>>(1, {i, j}));
    vector<vector<char>> &board = *board_ptr;
    while (!q.empty())
    {
        const auto [x, y] = q.front();
        q.pop();
        if (x >= 0 && x < board.size() && y >= 0 && y < board[x].size() &&
            board[x][y] == 'W')
        {
            board[x][y] = 'T';
            q.emplace(x - 1, y);
            q.emplace(x + 1, y);
            q.emplace(x, y + 1);
            q.emplace(x, y - 1);
        }
    }
}

void FillSurroundedRegions(vector<vector<char>> *board_ptr)
{
    vector<vector<char>> &board = *board_ptr;
    for (int i = 0; i < board.size(); ++i)
    {
        MarkBoundaryRegion(i, 0, board_ptr);
        MarkBoundaryRegion(i, board[i].size() - 1, board_ptr);
    }

    for (int j = 0; j < board.front().size(); ++j)
    {
        MarkBoundaryRegion(0, j, board_ptr);
        MarkBoundaryRegion(board.size() - 1, j, board_ptr);
    }

    for (vector<char> &row : board)
    {
        for (char &c : row)
        {
            c = c != 'T' ? 'B' : 'W';
        }
    }
}

int main()
{
    vector<vector<char>> i = {{'B','B','B','B'},
                              {'W','B','W','B'}, 
                              {'B','W','W','B'}, 
                              {'B','B','B','B'}};
    for(auto j : i) {
        for(auto k : j) {
            k == 'B' ? cout << "*" : cout <<"o";
        }
        cout << endl;
    }
    cout << endl;
    FillSurroundedRegions(&i);
        for(auto j : i) {
        for(auto k : j) {
           k == 'B' ? cout << "*" : cout <<"o";
        }
        cout << endl;
    }

    return 0;
}