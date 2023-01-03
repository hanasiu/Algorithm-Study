#include <iostream>
#include <vector>
#include <numeric>


using namespace std;


string ConstructFromBase(int num_as_int, int base) {
	return num_as_int == 0 ? ""
		: ConstructFromBase(num_as_int / base, base) +
		(char)(num_as_int % base >= 10
			? 'A' + num_as_int % base - 10
			: '0' + num_as_int % base);
}


string ConvertBase(const string& num_as_string, int b1, int b2) {
	bool is_negative = num_as_string.front() == '-';
	int num_as_int =
		std::accumulate(num_as_string.begin() + is_negative, num_as_string.end(), 0,
			[b1](int x, char c) {
				return x * b1 + (isdigit(c) ? c - '0' : c - 'A' + 10);
			});
	return (is_negative ? "-" : "") +
		(num_as_int == 0 ? "0" : ConstructFromBase(num_as_int, b2));

}



int main()
{
	string num = "A74C";  // 42828
	string k = ConvertBase(num, 16, 10);
	cout << k;

	return 0;
}
