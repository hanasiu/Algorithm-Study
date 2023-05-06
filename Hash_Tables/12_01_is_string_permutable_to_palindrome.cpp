#include <iostream>
#include <unordered_set>

using namespace std;

bool CanFormPalindrome(const string& s) {
    unordered_set<char> chars_with_odd_frequency;
    for(char c: s) {
        if(chars_with_odd_frequency.count(c)) {
            chars_with_odd_frequency.erase(c);
        } else {
            chars_with_odd_frequency.insert(c);
        }
    }
    return chars_with_odd_frequency.size() <= 1;
}

int main() {
    string i = "edified";
    cout << CanFormPalindrome(i) << endl;
}