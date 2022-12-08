//이해가 안되면 본문 보자.
#include <iostream>
#include <vector>

using namespace std;

void DirectedPowerSet(const vector<int>& input_set, int to_be_selected,
	vector<int>* selected_so_far, vector<vector<int>>* power_set) {
	if (to_be_selected == input_set.size()) { // 사이즈에 도달하면 멈춤
		cout << "*** " << to_be_selected << endl;
		power_set->emplace_back(*selected_so_far);
		return;
	}
	selected_so_far->emplace_back(input_set[to_be_selected]);//포함
	DirectedPowerSet(input_set, to_be_selected + 1, selected_so_far, power_set);
	selected_so_far->pop_back();//미포함
	DirectedPowerSet(input_set, to_be_selected + 1, selected_so_far, power_set);
}

vector<vector<int>> GeneratePowerSet(const vector<int>& input_set) {
	vector<vector<int>> power_set; // {}에서 시작, input_set.size()까지 달림.
	DirectedPowerSet(input_set, 0, make_unique<vector<int>>().get(), &power_set);
	return power_set;
}



int main()
{
	vector<int> exam = { 1, 2, 3, 4 };
	vector<vector<int>> one = GeneratePowerSet(exam);
	for (vector<int> i : one) {
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}
	
	return 0;
}
