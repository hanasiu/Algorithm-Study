#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<string>> findAnagrams(const vector<string>& dictionary) {
	unordered_map<string, vector<string>> sorted_string_to_anagrams;
	for (const string& s : dictionary) {
		string sorted_str(s);
		sort(sorted_str.begin(), sorted_str.end());
		sorted_string_to_anagrams[sorted_str].emplace_back(s);
	}

	vector<vector<string>> anagram_groups;
	for (const auto& i : sorted_string_to_anagrams) {
		if (i.second.size() >= 2) {
			anagram_groups.emplace_back(i.second); // 제대로 되는지 확인 필요
		}
	}
	return anagram_groups;
}

int main()
{
	
	return 0;
}
