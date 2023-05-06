#include <algorithm>
#include <cmath>
#include <limits>
#include <iostream>

using namespace std;

typedef enum
{
    kSmaller,
    kEqual,
    kLarger
} Ordering;

Ordering Compare(double a, double b)
{
    double diff = (a - b) / max(abs(a), abs(b));
    return diff < -numeric_limits<double>::epsilon()
               ? kSmaller
           : diff > numeric_limits<double>::epsilon() ? kLarger
                                                      : kEqual;
}

double SquareRoot(double x)
{
    int count = 0;
    double left, right;
    if (x < 1.0)
    {
        left = x, right = 1.0;
    }
    else
    {
        left = 1.0, right = x;
    }

    while (Compare(left, right) != kEqual)
    {
        ++count;
        double mid = left + 0.5 * (right - left);
        double mid_squared = mid * mid;
        if (Compare(mid_squared, x) == kLarger)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
    }
    cout << count << endl;
    return left;
}

int main()
{
    double x = 11.1;
    double ex = SquareRoot(x);
    cout << ex << endl;
    return 0;
}