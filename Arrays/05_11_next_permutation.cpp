#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<int> NextPermutation(vector<int> perm)
{
    auto inversion_point = is_sorted_until(perm.rbegin(), perm.rend());

    if (inversion_point == rend(perm))
    {
        return {};
    }

    auto least_upper_bound = upper_bound(perm.rbegin(), inversion_point, *inversion_point);

    iter_swap(inversion_point, least_upper_bound);
    reverse(perm.rbegin(), inversion_point);
    return perm;
}

int main() {
    vector<int> i = {9, 4, 3, 1, 7, 5, 11, 8, 4, 1};
    vector<int> k = NextPermutation(i);
    for(auto j : k) {
        cout << j << " ";
    }
}