#include <iostream>
#include <tuple>

using namespace std;

struct MinMax
{
    int smallest, largest;
};

MinMax FindMinMax(const vector<int> &A)
{
    if (A.size() <= 1)
    {
        return {A.front(), A.front()};
    }

    int global_min, global_max;
    tie(global_min, global_max) = minmax(A[0], A[1]);
    for (int i = 2; i + 1 < A.size(); i += 2)
    {
        const auto &[local_min, local_max] = minmax(A[i], A[i + 1]);
        global_min = min(global_min, local_min);
        global_max = max(global_max, local_max);
    }

    if (A.size() % 2)
    {
        global_min = min(global_min, A.back());
        global_max = max(global_max, A.back());
    }
    return {global_min, global_max};
}

int main()
{
    vector<int> k = {100, 55, 22, 33, 11, 44, 12, 31, 1111, 222, 333};
    MinMax i = FindMinMax(k);
    cout << i.smallest << " " << i.largest << endl;
    return 0;
}