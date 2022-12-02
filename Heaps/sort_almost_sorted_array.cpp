#pragma once
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> SortApproximatelySortedData(
	vector<int>::const_iterator sequence_begin,
	const vector<int>::const_iterator& sequence_end, int k) {
	priority_queue<int, vector<int>, greater<>> min_heap;

	for (int i = 0; i < k && sequence_begin != sequence_end; ++i) {
		min_heap.push(*sequence_begin++);
	}
	
	vector<int> result;
	while (sequence_begin != sequence_end) {
		min_heap.push(*sequence_begin++);
		result.emplace_back(min_heap.top());
		min_heap.pop();
	}

	while (!empty(min_heap)) {
		result.emplace_back(min_heap.top());
		min_heap.pop();
	}

	return result;
}

int main()
{
	
	return 0;
}
