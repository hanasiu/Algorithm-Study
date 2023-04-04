#include <iostream>
#include <vector>
#include <memory>

using namespace std;


struct Item {
	int weight, value;
	Item(int i, int j) : weight(i), value(j) { }
};

int OptimumSubjectToItemAndCapacity(const vector<Item>& items, int k, // input, input의 크기(-1, array)
	int available_capacity, vector<vector<int>>* v_ptr) { // capacity, 결과값 목록
	if (k < 0) {
		return 0;
	}

	vector<vector<int>>& v = *v_ptr;
	if (v[k][available_capacity] == -1) { // 왜 -1일까? -> line 36
		int without_curr_item = OptimumSubjectToItemAndCapacity( // recursion
			items, k - 1, available_capacity, v_ptr); //현재값 없이
		int with_curr_item =
			available_capacity < items[k].weight ? 0 // 현재값이 capacity보다 크면 0
			: items[k].value + OptimumSubjectToItemAndCapacity( // 현재값이 capacity보다 작으면 recursion
				items, k - 1,
				available_capacity - items[k].weight,
				v_ptr);
		v[k][available_capacity] = std::max(without_curr_item, with_curr_item); // 둘중 더 큰 거
	}
	return v[k][available_capacity];
}

int OptimumSubjectToCapacity(const vector<Item>& items, int capacity) {
	vector<vector<int>> i(items.size(), vector<int>(capacity + 1, -1));
	return OptimumSubjectToItemAndCapacity(
		items, items.size() -1, capacity,
		&i);
}

int main()
{
	Item a = Item(10, 50);
	Item b = Item(20, 100);
	Item c = Item(30, 400);
	Item d = Item(5, 200);
	Item f = Item(15, 200);
	vector<Item> items = { a,b,c,d,f };
	cout << OptimumSubjectToCapacity(items, 60);
	return 0;
}
