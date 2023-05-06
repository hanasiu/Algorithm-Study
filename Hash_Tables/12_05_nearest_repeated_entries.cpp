#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;

int FindNearestRepetition(const vector<string>& paragraph) {
    unordered_map<string, int> word_to_latest_index;
    int nearest_repeated_distance = numeric_limits<int>::max();
    for(int i = 0; i<paragraph.size(); ++i) {
        auto latest_equal_word = word_to_latest_index.find(paragraph[i]);
        if(latest_equal_word != word_to_latest_index.end()) {
            nearest_repeated_distance = 
            min(nearest_repeated_distance, i - latest_equal_word->second);
        }
        word_to_latest_index[paragraph[i]] = i;
    }
    return nearest_repeated_distance != numeric_limits<int>::max()
    ? nearest_repeated_distance 
    : -1;
}

int main() {
    vector<string> paragraph = {"the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog", "the", "quick", "brown", "fox"};
    int nearest_repetition_distance = FindNearestRepetition(paragraph);
    if (nearest_repetition_distance == -1) {
        cout << "There are no repeating words in the paragraph.\n";
    } else {
        cout << "The nearest repetition distance is: " << nearest_repetition_distance << "\n";
    }
    return 0;
}