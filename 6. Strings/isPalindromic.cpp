#include <iostream>
#include <vector>

using namespace std;

bool isPalindromic(const string& s) {
	for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
		if (s[i] != s[j]) return false;
	}
	return true;
}

int main()
{
	string example = "noon";
	cout << isPalindromic(example);
	return 0;
}
