#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool NextPermutation(vector<int> *perm)
{
    auto inversion_point = is_sorted_until(perm->rbegin(), perm->rend());

    if (inversion_point == perm->rend())
    {
        return false;
    }

    auto least_upper_bound = upper_bound(perm->rbegin(), inversion_point, *inversion_point);

    iter_swap(inversion_point, least_upper_bound);
    reverse(perm->rbegin(), inversion_point);
    return true;
}

vector<vector<int>> Permutations(vector<int> A) {
    vector<vector<int>> result;
    sort(A.begin(), A.end());
    do {
        result.emplace_back(A);
    } while(NextPermutation(&A));//or std::next_permutation
    return result;
}

int main() {
    vector<int> i = { 4, 5, 6};
    vector<vector<int>> k = Permutations(i);
    for(auto j : k) {
        for(auto l : j) {
            cout << l << " ";
        }
        cout << endl;
    }
}