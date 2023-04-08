#include <tuple>
#include <functional>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct HashTuple
{
    size_t operator()(const tuple<int, int, int> &t) const
    {
        return hash<int>()(get<0>(t) ^ get<1>(t) * 1021 ^ get<2>(t) * 1048573);
    }
};

bool IsPatternSuffixContainedStartingAtXY(
    const vector<vector<int>> &grid, int x, int y, const vector<int> &pattern,
    int offset,
    unordered_set<tuple<int, int, int>, HashTuple> *previous_attempts)
{
    if (pattern.size() == offset)
    {
        return true;
    }

    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[x].size() ||
        previous_attempts->find(make_tuple(x, y, offset)) != (*previous_attempts).cend() ||
        grid[x][y] != pattern[offset])
    {
        return false;
    }

    if(IsPatternSuffixContainedStartingAtXY(grid, x-1, y, pattern, offset+1, previous_attempts)||
    IsPatternSuffixContainedStartingAtXY(grid, x+1, y, pattern, offset+1, previous_attempts)||
    IsPatternSuffixContainedStartingAtXY(grid, x, y-1, pattern, offset+1, previous_attempts)||
    IsPatternSuffixContainedStartingAtXY(grid, x, y+1, pattern, offset+1, previous_attempts)) {
        return true;
    }
    previous_attempts->emplace(x,y,offset);
    return false;
}

bool IsPatternContainedInGrid(const vector<vector<int>>& grid,
const vector<int>& pattern) {
    unordered_set<tuple<int,int,int>, HashTuple> index;
    for(int i = 0; i< grid.size(); ++i) {
        for(int j = 0; j<grid[i].size(); ++j) {
            if(IsPatternSuffixContainedStartingAtXY(grid,i,j,pattern,0, &index)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>> i = {{1,2,3}, {3,4,5}, {5,6,7}};
    vector<int> pattern = {1,3,4,6};
    cout << IsPatternContainedInGrid(i, pattern) << endl;
    return 0;
}