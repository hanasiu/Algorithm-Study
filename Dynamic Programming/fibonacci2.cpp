#pragma once
#include <iostream>

using namespace std;
//O(n) time and O(1) space
int fibonacci(int n) {
	if (n <= 1) {
		return n;
	}

	int f_minus_2 = 0, f_minus_1 = 1;
	for (int i = 2; i <= n; ++i) {
		int f = f_minus_2 + f_minus_1;
		f_minus_2 = f_minus_1;
		f_minus_1 = f;
	}
	return f_minus_1;
}

int main()
{
	cout << fibonacci(10);
	return 0;
}
