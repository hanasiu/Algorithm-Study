//EPI P.271
#include <iostream>
#include <vector>

using namespace std;

int FindMaximumSubarray(const vector<int>& A) {
	int max_seen = 0, max_end = 0;
	for (int a : A) {
		max_end = max(a, a + max_end); // std::max returns the greater of a and b.
		max_seen = max(max_seen, max_end);
	}
	return max_seen;
}

int main()
{
	vector<int> example = { -2,3,1,-1,3,2,-1 };
	int result = FindMaximumSubarray(example);
	cout << result;
	return 0;
}
