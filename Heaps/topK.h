#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>


using namespace std;

auto comp = [](string a, string b) {return a.size() >= b.size(); };

vector<string> topK(int k, vector<string>::const_iterator stream_begin,
	const vector<string>::const_iterator& stream_end) {
	priority_queue<string, vector<string>, decltype(comp)> min_heap(comp);
	while (stream_begin != stream_end) {
		min_heap.emplace(*stream_begin);
		if (min_heap.size() > k) {
			min_heap.pop();
		}
		stream_begin = std::next(stream_begin);
	}
	vector<string> result;
	while (!min_heap.empty()) {
		result.emplace_back(min_heap.top());
		min_heap.pop();
	}
	return result;
}
