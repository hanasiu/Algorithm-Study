#pragma once
#include <list>
#include <algorithm>

using namespace std;

class Queue {
public:
	void enqueue(int x) { data_.emplace_back(x); }

	int dequeue() {
		const int val = data_.front();
		data_.pop_front();
		return val;
	}

	int getMax() const { return *max_element(data_.begin(), data_.end()); }
private:
	list<int> data_;
};
