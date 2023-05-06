#pragma once
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int stringHash(const string& s, int modulus) {
	const int kMult = 997;
	return accumulate(s.begin(), s.end(), 0, [kMult, modulus](int val, char c) {
		return (val * kMult + c) % modulus;
	});
}

int main()
{
	string example = "hanasiyou";
	cout << stringHash(example, 11);
	return 0;
}
