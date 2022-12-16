#include <iostream>
#include <vector>

using namespace std;

int SearchFirstOfK(const vector<int>& A, int k) {
	int left = 0, right = A.size() - 1, result = -1;

	while (left <= right) {
		int mid = left + ((right - left) / 2);
		if (A[mid] > k) {
			right = mid - 1;
		}
		else if (A[mid] == k) {
			result = mid;
			right = mid - 1;
		}
		else {//A[mid]<k
			left = mid + 1;
		}
	}
	return result;
}

int main()
{
	vector<int> i = { -14,-10,2,108,108,243,285,285,401 };
	cout << SearchFirstOfK(i, 108);
	return 0;
}
