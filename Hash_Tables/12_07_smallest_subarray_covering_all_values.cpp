#include <iostream>
// #include <vector>
// #include <unordered_map>
// #include <unordered_set>
// #include <list>

using namespace std;

struct Subarray {
    int start, end;
};

Subarray FindSmallestSequentiallyCoveringSubset(
    const vector<string>& paragraph, const vector<string>& keywords
) {
    unordered_map<string, int> keyword_to_idx;

    for(int i = 0; i< keywords.size(); ++i) {
        keyword_to_idx.emplace(keywords[i], i);
    }

    vector<int> latest_occurrence(size(keywords), -1);

    vector<int> shortest_subarray_length(size(keywords), numeric_limits<int>::max());

    int shortest_distance = numeric_limits<int>::max();
    Subarray result = Subarray{-1, -1};
    for(int i = 0; i< size(paragraph); ++i) {
        if(keyword_to_idx.count(paragraph[i])) {
            int keyword_idx = keyword_to_idx.find(paragraph[i])->second;
            if(keyword_idx == 0) {
                shortest_subarray_length[keyword_idx] = 1;
            } else if (shortest_subarray_length[keyword_idx -1] !=
            numeric_limits<int>::max()) {
                int distance_to_previous_keyword = i - latest_occurrence[keyword_idx -1];
                shortest_subarray_length[keyword_idx] = 
                distance_to_previous_keyword + shortest_subarray_length[keyword_idx - 1];
            }
            latest_occurrence[keyword_idx] = i;
            if(keyword_idx == size(keywords) -1 &&
            shortest_subarray_length.back() < shortest_distance) {
                shortest_distance = shortest_subarray_length.back();
                result = { i-shortest_subarray_length.back() + 1, i};
            } 
        }
    }
    return result;
}

int main() {
    vector<string> example_paragraph = {
        "Union", "and", "is", "not", "either", "to", "save"
    };
    vector<string> example_keywords = {
        "Union", "save"
    };

    Subarray i = FindSmallestSequentiallyCoveringSubset(example_paragraph, example_keywords);
    cout << i.start << " " << i.end << endl;
}