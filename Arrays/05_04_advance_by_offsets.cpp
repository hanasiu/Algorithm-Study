#include <iostream>

using namespace std;

bool CanReachEnd(const vector<int> &max_advance_steps)
{
    int furthest_reach_so_far = 0, last_index = max_advance_steps.size() - 1;
    for (int i = 0;
         i <= furthest_reach_so_far && furthest_reach_so_far < last_index;
         ++i)
    {
        furthest_reach_so_far = max(furthest_reach_so_far, max_advance_steps[i] + i);
    }
    return furthest_reach_so_far >= last_index;
}

int main()
{
    vector<int> i = {3, 3, 1, 0, 2, 0, 1};
    bool a = CanReachEnd(i);
    cout << a << endl;

    vector<int> k = {3, 2, 0, 0, 2, 0, 1};
    bool b = CanReachEnd(k);
    cout << b << endl;
    return 0;
}

// clang++ --std=c++14 05_04_advance_by_offsets.cpp && ./a.out && rm a.out
