#include <iostream>
#include <bitset>

using namespace std;

vector<int> GrayCode(int num_bits) {
    if(num_bits == 0) {
        return {0};
    }

    vector<int> gray_code_num_bits_minus_1 = GrayCode(num_bits - 1);

    int leading_bit_one = 1 << (num_bits - 1);

    for(int i = gray_code_num_bits_minus_1.size() - 1; i >= 0; --i) {
        gray_code_num_bits_minus_1.emplace_back(leading_bit_one | gray_code_num_bits_minus_1[i]);
    }
    return gray_code_num_bits_minus_1;
}

int main() {
    vector<int> i = GrayCode(4);
    for(auto k : i) {
        cout << std::bitset<4>(k) << endl;
    }
    return 0;
}