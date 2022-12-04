#pragma once
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct IteratorCurrentAndEnd {
		bool operator>(const IteratorCurrentAndEnd& that) const {
			return *current > *that.current;
	};

	vector<int>::const_iterator current;
	vector<int>::const_iterator end;
};

vector<int> MergeSortedArrays(const vector<vector<int>>& sorted_arrays) {
	priority_queue<IteratorCurrentAndEnd, vector<IteratorCurrentAndEnd>,
		greater<>> min_heap;

	for (const vector<int>& sorted_array : sorted_arrays) {
		if (!sorted_array.empty()) {
			min_heap.emplace(IteratorCurrentAndEnd{ cbegin(sorted_array), cend(sorted_array) });
		}
	}

	vector<int> result;
	while (min_heap.empty()) {
		IteratorCurrentAndEnd smallest_array = min_heap.top();
		min_heap.pop();
		result.emplace_back(*smallest_array.current);
		if (std::next(smallest_array.current) != smallest_array.end) {
			min_heap.emplace(IteratorCurrentAndEnd{ std::next(smallest_array.current), smallest_array.end });
		}
	}
	return result;
}

int main()
{
	
	return 0;
}
