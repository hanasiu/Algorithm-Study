#include <iostream>
#include <vector>


using namespace std;

bool HasTwoSum(const vector<int>& A, int t) {
	int i = 0, j = A.size() - 1;
	while (i <= j) {
		if (A[i] + A[j] == t) {
			cout << A[i] << " " << A[j];
			return true;
		}
		else if (A[i] + A[j] < t) {
			++i;
		}
		else { // A[i] + A[j} > t 
			--j;
		}
	}
	return false;
}

int main()
{
	vector<int> i = { -5, -2, 5, 9, 13, 15, 19, 21, 26 };
	HasTwoSum(i, 28);

	return 0;
}
