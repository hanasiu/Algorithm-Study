#pragma once
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> cache;
//O(n) storage
int fibonacci(int n) {
	if (n <= 1) {
		return n;
	}
	else if (!cache.count(n)) {
		cache[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}
	return cache[n];
}
int main()
{
	cout << fibonacci(10);
	return 0;
}
