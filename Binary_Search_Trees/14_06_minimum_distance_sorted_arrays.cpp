#include <iostream>
#include <map>

using namespace std;

int FindClosestElementsInSortedArrays(
    const vector<vector<int>> &sorted_arrays)
{
    struct IterTail
    {
        vector<int>::const_iterator iter, tail;
    };

    multimap<int, IterTail> iter_and_tail;
    for (const vector<int> &sorted_array : sorted_arrays)
    {
        iter_and_tail.emplace(sorted_array.front(), IterTail{cbegin(sorted_array), cend(sorted_array)});
    }

    int min_distance_so_far = numeric_limits<int>::max();
    while (true)
    {
        int min_value = cbegin(iter_and_tail)->first,
            max_value = crbegin(iter_and_tail)->first;
        min_distance_so_far = min(max_value - min_value, min_distance_so_far);
        const auto next_min = next(cbegin(iter_and_tail)->second.iter),
                   next_end = cbegin(iter_and_tail)->second.tail;

        if (next_min == next_end)
        {
            return min_distance_so_far;
        }
        iter_and_tail.emplace(*next_min, IterTail{next_min, next_end});
        iter_and_tail.erase(cbegin(iter_and_tail));
    }
}

int main() {
    vector<vector<int>> example = {{5,10,15}, {3,6,9,12,15}, {8,17,24}};
    int result = FindClosestElementsInSortedArrays(example);
    cout << result << endl;
    return 0;
}