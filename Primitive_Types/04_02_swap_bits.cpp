#include <iostream>
#include <bitset>

using namespace std;

long long SwapBits(long long x, int i, int j)
{
    if (((x >> i) & 1) != ((x >> j) & 1))
    {
        unsigned long long bit_mask = (1L << i) | (1L << j);
        cout << "test" << endl;
        x ^= bit_mask;
    }
    cout << (((x >> i) & 1) != ((x >> j) & 1));
    cout << endl;

    return x;
}
int main()
{
    // Test cases
    long long x1 = 10; // binary: 1010
    int i1 = 0;
    int j1 = 3;

    long long x2 = 7; // binary: 0111
    int i2 = 0;
    int j2 = 2;
    long long result1 = SwapBits(x1, i1, j1);
    long long result2 = SwapBits(x2, i2, j2);

    cout << "Original x1: " << x1 << ", Binary: " << bitset<64>(x1) << endl;
    cout << "Result1: " << result1 << ", Binary: " << bitset<64>(result1) << endl;

    cout << "Original x2: " << x2 << ", Binary: " << bitset<64>(x2) << endl;
    cout << "Result2: " << result2 << ", Binary: " << bitset<64>(result2) << endl;

    return 0;
}