#include <vector>
#include <iostream>

using namespace std;

int ComputeNumberOfWaysToXY(int x, int y, vector<vector<int>> *number_of_ways_ptr)
{
    if (x == 0 && y == 0)
    {
        return 1;
    }

    vector<vector<int>> &number_of_ways = *number_of_ways_ptr;
    if (number_of_ways[x][y] == 0)
    {
        int ways_left =
            x == 0 ? 0 : ComputeNumberOfWaysToXY(x - 1, y, number_of_ways_ptr);
        int ways_top =
            y == 0 ? 0 : ComputeNumberOfWaysToXY(x, y - 1, number_of_ways_ptr);
        number_of_ways[x][y] = ways_top + ways_left;
    }
    return number_of_ways[x][y];
}

int NumberOfWays(int n, int m)
{
    vector<vector<int>> number_of_ways(n, vector<int>(m, 0));
    return ComputeNumberOfWaysToXY(
        n - 1, m - 1,
        &number_of_ways);
}

int main()
{
    cout << NumberOfWays(5, 5);
    return 0;
}