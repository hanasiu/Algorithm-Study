#include <iostream>
#include <vector>
#include <algorithm>


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

bool HasThreeSum(vector<int> A, int t) {
	sort(A.begin(), A.end());

	return std::any_of(A.begin(), A.end(), [&](int a) { return HasTwoSum(A, t - a);  });
}

int main()
{
	vector<int> i = { 2,3,5,7,11 };
	cout << endl << HasThreeSum(i, 21);
	

	return 0;
}
