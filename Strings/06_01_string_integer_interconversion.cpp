#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

string IntToString(int x) {
	bool is_negative = false;
	if (x < 0) {
		is_negative = true;
	}
	
	string s;
	do {
		s += '0' + abs(x % 10);
		x /= 10;
	} while (x);

	s += is_negative ? "-" : "";
	return { rbegin(s), rend(s) };
}

int StringToInt(const string& s) {
	return (s[0] == '-' ? -1 : 1) * std::accumulate(s.begin() + (s[0] == '-'), s.end(),
		0, [](int running_sum, char c) {
			return running_sum * 10 + c - '0';
		});
}


int main()
{
	string i = IntToString(10);
	cout << i << endl;
	int j = StringToInt("300");
	cout << j << endl;

	return 0;
}
