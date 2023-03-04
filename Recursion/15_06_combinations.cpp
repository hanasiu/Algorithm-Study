#include <iostream>
#include <memory>
#include <vector>

using namespace std;


//1,2,3,4에서 1을 빼고 k-1개 고르기/ 1을 넣고 k개 고르기
void DirectedCombinations(int n, int k, int offset,
	vector<int>* partial_combination, vector<vector<int>>* result) {
	if ((*partial_combination).size() == k) { // k개 골랐으면 result에 넣기
		result->emplace_back(*partial_combination);
		return;
	}
	const int num_remaining = k - (*partial_combination).size(); // k에서 골라둔 거의 크기 빼기 
	for (int i = offset; i <= n && num_remaining <= n - i + 1; ++i) {
		partial_combination->emplace_back(i); // i를 넣음
		DirectedCombinations(n, k, i + 1, partial_combination, result); // recursion
		partial_combination->pop_back(); // i를 뺌
	}
}

vector<vector<int>> Combinations(int n, int k) {
	vector<vector<int>> result;
	DirectedCombinations(n, k, 1, make_unique<vector<int>>().get(), &result);
	return result;
}

int main()
{
	vector<vector<int>> i = Combinations(7, 3);
	for (vector<int> j : i) {
		for (auto k : j) {
			cout << k << " ";
		}
		cout << endl;
	}

	return 0;
}
