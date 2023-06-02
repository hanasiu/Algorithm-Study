#include <iostream>
#include <vector>

using namespace std;

vector<int> Multiply(vector<int> num1, vector<int> num2)
{
    const int sign = (num1.front() < 0) ^ (num2.front() < 0) ? -1 : 1;
    num1.front() = abs(num1.front()), num2.front() = abs(num2.front());

    vector<int> result(num1.size() + num2.size(), 0);
    for (int i = num1.size() - 1; i >= 0; --i)
    {
        for (int j = num2.size() - 1; j >= 0; --j)
        {
            result[i + j + 1] += num1[i] * num2[j];
            result[i + j] += result[i + j + 1] / 10;
            result[i + j + 1] %= 10;
        }
    }
    result = {
        find_if_not(result.begin(), result.end(), [](int a)
                    { return a == 0; }),
        result.end()};
    if (result.empty())
    {
        return {0};
    }
    result.front() *= sign;
    return result;
}


int main() {
    vector<int> i = {1,9,3,7};
    vector<int> j = {-4,5,8,3};
    vector<int> result = Multiply(i, j);
    for(auto k : result) {
        cout<< k;
    }
    cout << endl;
    return 0;
}