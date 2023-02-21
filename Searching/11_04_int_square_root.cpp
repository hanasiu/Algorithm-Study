#include <iostream> 

int SquareRoot(int k)
{
    int left = 0, right = k;
    while (left <= right)
    {
        long long mid = left + ((right - left) / 2);
        long long mid_squared = mid * mid;
        if (mid_squared <= k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return left - 1;
}

int main() {
    int k = 111;
    int result = SquareRoot(k);
    std::cout << "The square root of " << k << " is " << result << std::endl;
    return 0;
}