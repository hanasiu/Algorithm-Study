#include <iostream>
#include <vector>

using namespace std;

vector<int> IntersectTwoSortedArrays(const vector<int>& A,
	const vector<int>& B) {
	vector<int> intersection_A_B;
	int i = 0, j = 0;
	while (i < A.size() && j < B.size()) {
		if (A[i] == B[j] && (i == 0 || A[i] != A[i - 1])) {
			intersection_A_B.emplace_back(A[i]);
			++i, ++j;
		}
		else if (A[i] < B[j]) {
			++i;
		}
		else { // A[i]> B[j]
			++j;
		}
	}
	return intersection_A_B;
}


int main()
{
	vector<int> A = { 2,3,3,5,7,11, 31, 66 };
	vector<int> B = { 3,3,7,11,15,31, 33, 35, 66 };
	vector<int> i = IntersectTwoSortedArrays(A, B);
	for (auto k : i) {
		cout << k << " ";
	}
	return 0;
}
