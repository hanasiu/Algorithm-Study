#include <iostream>
#include <vector>

using namespace std;

vector<int> PlusOne(vector<int> A)
{
    ++A.back();
    for (int i = A.size() - 1; i > 0 && A[i] == 10; --i)
    {
        A[i] = 0, ++A[i - 1];
    }
    if (A[0] == 10)
    {
        A[0] = 1;
        A.emplace_back(0);
    }
    return A;
}

int main()
{
    vector<int> k = {9, 9, 9, 9, 9};
    vector<int> i = {1, 2, 3, 4, 9, 9};

    vector<int> k1 = PlusOne(k);
    vector<int> i1 = PlusOne(i);

    for (auto j : k1)
    {
        cout << j;
    }
    cout << endl;
    for (auto q : i1)
    {
        cout << q;
    }
    return 0;
}