#include <iostream>

using namespace std;

struct Number
{
    Number(int a, int b) : a(a), b(b), val(a + b * sqrt(2)) {}

    int a, b;
    double val;
};

vector<double> GenerateFirstKABSqrt2(int k)
{
    vector<Number> cand;
    cand.emplace_back(0, 0);
    int i = 0, j = 0;
    for (int n = 1; n < k; ++n)
    {
        Number cand_i_plus_1(cand[i].a + 1, cand[i].b);
        Number cand_j_plus_sqrt2(cand[j].a, cand[j].b + 1);
        cand.emplace_back(
            min(cand_i_plus_1, cand_j_plus_sqrt2,
                [](const Number &a, const Number &b)
                { return a.val < b.val; }));
        if (cand_i_plus_1.val == cand.back().val)
        {
            ++i;
        }
        if (cand_j_plus_sqrt2.val == cand.back().val)
        {
            ++j;
        }
    }
    vector<double> result;
    transform(cand.begin(), cand.end(), back_inserter(result),
              [](const Number &c)
              { return c.val; });
    return result;
}

int main()
{
    vector<double> i = GenerateFirstKABSqrt2(10);
    for (auto k : i)
    {
        cout << k << endl;
    }
    return 0;
}