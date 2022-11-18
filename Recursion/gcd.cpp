#pragma once
#include <iostream>

using namespace std;

long long gcd(long long x, long long y) {
	return y == 0 ? x : gcd(y, x % y);
}

int main()
{
	cout << gcd(210, 45);
	return 0;
}
