#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

bool IsWellFormed(const string& s) {
    stack<char> left_chars;
    const unordered_map<char, char> kLookup = {
        {'(', ')'}, {'{', '}'}, {'[', ']'}
    };
    for(int i = 0; i<s.size(); ++i) {
        if(kLookup.count(s[i])) {
            left_chars.emplace(s[i]);
        } else {
            if(left_chars.empty() || kLookup.at(left_chars.top()) != s[i]) {
                return false;
            }
            left_chars.pop();
        }
    }
    return left_chars.empty();
}

int main() {
    string example = "[()[]{()()}]";
    string example2 = "{(})";
    cout << IsWellFormed(example) << endl;
    cout << IsWellFormed(example2) << endl;
    return 0;
}