//EPI P.25
#include <iostream>
#include <vector>

using namespace std;

short countBits(unsigned int x) {
	short num_bits = 0;
	while (x) {
		num_bits += x & 1;
		x >>= 1;
	}
	return num_bits;
}

int main()
{
	unsigned int a = 2555555;
	cout << countBits(a);
	
	return 0;
}
