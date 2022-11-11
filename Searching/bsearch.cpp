#include <iostream>
#include <vector>

using namespace std;

int bsearch(int t, const vector<int>& A) {
	int L = 0, U = A.size() - 1;
	while (L <= U) {
		int M = L + (U - L) / 2; // overflow: int M = (L+U) / 2; 
		if (A[M] < t) {
			L = M + 1;
		}
		else if (A[M] == t) {
			return M;
		}
		else {
			U = M - 1;
		}
	}
	return -1;
}

int main()
{
	vector<int> i = { 1, 2, 3, 4, 10, 11, 12, 13, 14, 18, 20, 25, 33, 41 };
	cout << bsearch(33, i);
	return 0;
}
