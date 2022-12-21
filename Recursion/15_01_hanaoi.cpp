include <iostream>
#include <vector>
#include <stack>
#include <array>


using namespace std;

const int kNumPegs = 3;

void ComputeTowerHanoiSteps(int num_rings_to_move,
	array<stack<int>, kNumPegs>& pegs, int from_peg, int to_peg, int use_peg,
	vector<vector<int>>* result_ptr) {
	if (num_rings_to_move > 0) {
		ComputeTowerHanoiSteps(num_rings_to_move - 1, pegs, from_peg, use_peg,
			to_peg, result_ptr);
		pegs[to_peg].push(pegs[from_peg].top());
		pegs[from_peg].pop();
		result_ptr->emplace_back(vector<int>{from_peg, to_peg});
		ComputeTowerHanoiSteps(num_rings_to_move - 1, pegs, use_peg, to_peg,
			from_peg, result_ptr);
	}
}

vector<vector<int>> ComputeTowerHanoi(int num_rings) {
	array<stack<int>, kNumPegs> pegs;
	for (int i = num_rings; i >= 1; --i) {
		pegs[0].push(i);
	}

	vector<vector<int>> result;
	ComputeTowerHanoiSteps(num_rings, pegs, 0, 1, 2, &result);
	return result;
}


int main()
{
	vector<vector<int>> i = ComputeTowerHanoi(5);
	for (auto &j : i) {
		for (auto k : j)
			cout << k << " ";
		cout << endl;
	}
	
	return 0;
}
