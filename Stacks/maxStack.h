#pragma once
#include <stack>

using namespace std;

class Stack {
	bool empty() const {
		return element_with_cached_max_.empty();
	}

	int getMax() const {
		return element_with_cached_max_.top().max;
	}

	int pop() {
		int pop_element = element_with_cached_max_.top().element;
		element_with_cached_max_.pop();
		return pop_element;
	}

	void push(int x) {
		element_with_cached_max_.emplace(elementWithCachedMax{ x, std::max(x, (empty() ? x : max())) });
	}
private:
	struct elementWithCachedMax {
		int element, max;
	};
	stack<elementWithCachedMax> element_with_cached_max_;
};
