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

vector<int> SortKIncreasingDecreasingArray(const vector<int>& A) {
	vector<vector<int>> sorted_subarrays;
	enum SubarrayType { kIncreasing, kDecreasing };
	SubarrayType subarray_type = kIncreasing;
	int start_idx = 0;
	for (int i = 1; i <= A.size(); ++i) {
		if (i == A.size() ||
			(A[i - 1] < A[i] && subarray_type == kDecreasing ||
				A[i - 1] >= A[i] && subarray_type == kIncreasing)) {
			if (subarray_type == kIncreasing) {
				sorted_subarrays.emplace_back(A.cbegin() + start_idx, A.cbegin() + i);
			}
			else {
				sorted_subarrays.emplace_back(A.crbegin() + A.size() - i, crbegin(A) + A.size() - start_idx);
			}
			start_idx = i;
			subarray_type =
				subarray_type == kIncreasing ? kDecreasing : kIncreasing;
		}

		return MergeSortedArrays(sorted_subarrays);
	}
}

int main()
{
	
	return 0;
}
