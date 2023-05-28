// #include <iostream>
// #include <vector>
// #include <iomanip> 

// using namespace std;

// vector<int> precomputed_reverse = {0b00,0b10,0b01,0b11};

// unsigned long long ReverseBits(unsigned long long x) {
//     const int kMaskSize = 2;
//     const int kBitMask = 0b11111111;
//     return precomputed_reverse[x & kBitMask] << (3*kMaskSize) |
//     precomputed_reverse[(x >> kMaskSize) & kBitMask] << (2*kMaskSize) |
//     precomputed_reverse[(x >> (2 * kMaskSize)) & kBitMask] << (kMaskSize) |
//     precomputed_reverse[(x  >> (3 * kMaskSize)) & kBitMask];
// }

// int main() {
//     unsigned long long i = 0x10010011;
//     cout << hex << setw(8) << setfill('0') << i << endl; // Print i in hexadecimal format
//     unsigned long long k = ReverseBits(i);
//     cout << hex << setw(8) << setfill('0') << k << endl; // Print
// }

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<int> precomputed_reverse = {0b00, 0b10, 0b01, 0b11};

unsigned char ReverseBits(unsigned char x) {
    const int kBlockSize = 2;
    const int kNumBlocks = 4; // Number of 2-bit blocks in an 8-bit value
    const int kBlockMask = (1 << kBlockSize) - 1;

    return precomputed_reverse[x & kBlockMask] << (kBlockSize * 3) |
    precomputed_reverse[(x >> kBlockSize) & kBlockMask] << (kBlockSize * 2) |
    precomputed_reverse[(x >> (2 * kBlockSize)) & kBlockMask] << (kBlockSize * 1) |
    precomputed_reverse[(x >> (3 * kBlockSize)) & kBlockMask];
}

int main() {
    unsigned char i = 0b10010011;
    cout << "Input:    " << bitset<8>(i) << endl;
    unsigned char k = ReverseBits(i);
    cout << "Reversed: " << bitset<8>(k) << endl;

    return 0;
}
