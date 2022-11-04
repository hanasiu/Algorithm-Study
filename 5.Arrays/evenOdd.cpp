#include <iostream>
#include <vector>

using namespace std;

void evenOdd(vector<int>& A_ptr) {
	int next_even = 0, next_odd = A_ptr.size() - 1;
	while (next_even < next_odd) {
		if (A_ptr[next_even] % 2 == 0) {
			++next_even;
		}
		else {
			swap(A_ptr[next_even], A_ptr[next_odd--]);
		}
	}
}

int main()
{
	vector<int> example = { 1, 3, 4, 2, 7, 9, 100, 200, 201, 300, 333 };
	evenOdd(example);
	for (auto i : example) {
		cout << i << " ";
	}
	
	return 0;
}
