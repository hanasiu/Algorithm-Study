#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <list>

using namespace std;

struct Subarray
{
    int start, end;
};

Subarray FindSmallestSubarrayCoveringSet(
    const vector<string> &paragraph, const unordered_set<string> &keywords)
{
    unordered_map<string, int> keywords_to_cover;
    for (const string &keyword : keywords)
    {
        ++keywords_to_cover[keyword];
    }

    Subarray result = Subarray{-1, -1};
    int remaining_to_cover = keywords.size();
    for (int left = 0, right = 0; right < paragraph.size(); ++right)
    {
        if (keywords.count(paragraph[right]) &&
            --keywords_to_cover[paragraph[right]] >= 0)
        {
            --remaining_to_cover;
        }

        while (remaining_to_cover == 0)
        {
            if ((result.start == -1 && result.end == -1) ||
                right - left < result.end - result.start)
            {
                result = {left, right};
            }
            if (keywords.count(paragraph[left]) &&
                ++keywords_to_cover[paragraph[left]] > 0)
            {
                ++remaining_to_cover;
            }
            ++left;
        }
    }
    return result;
}

Subarray FindSmallestSubarrayCoveringSet(
    vector<string>::const_iterator paragraph_begin,
    vector<string>::const_iterator paragraph_end,
    vector<string>& keywords
) {
    list<int> loc;
    unordered_map<string, list<int>::iterator> dict;
    for(const string& s : keywords){
        dict.emplace(s, loc.end());
    }

    Subarray result = Subarray{-1, -1};
    int idx = 0;
    while(paragraph_begin != paragraph_end) {
        string s = *paragraph_begin++;
        auto it = dict.find(s);
        if(it!= dict.end()) {
            if(it->second!=loc.end()) {
                loc.erase(it->second);
            }
            loc.emplace_back(idx);
            it->second = --loc.end();

            if(loc.size() == keywords.size()) {
                if((result.start == -1 && result.end == -1)||
                idx - loc.front() < result.end - result.start) {
                    result = {loc.front(), idx};
                }
            }
        }
        ++idx;
    }
    return result;
}

int main() {
    const vector<string> i = {"apple", "banana", "apple","apple", "dog", "cat", "apple", "dog",
    "banana", "apple", "cat", "dog"};
    unordered_set<string> keywords = {"apple", "banana", "cat"};
    vector<string> keywordsVector = {"apple", "banana", "cat"};
    Subarray k = FindSmallestSubarrayCoveringSet(i, keywords);
    cout << k.start << " " << k.end << endl;
    Subarray j = FindSmallestSubarrayCoveringSet(
    i.begin(), i.end(), keywordsVector);
    cout << j.start << " " << j.end << endl;
    return 0;
}