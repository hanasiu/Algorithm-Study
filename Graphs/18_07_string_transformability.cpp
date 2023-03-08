#include <queue>
#include <unordered_set>
#include <iostream>

using namespace std;

int TransformString(unordered_set<string> D, const string& s,
const string& t) {
    struct StringWithDistance {
        string candidate_string;
        int distance;
    };
    queue<StringWithDistance> q;
    D.erase(s);
    q.emplace(StringWithDistance{s, 0});

    while(!q.empty()) {
        StringWithDistance f(q.front());
        if(f.candidate_string == t) {
            return f.distance;
        }

        string str = f.candidate_string;
        for(int i = 0; i<str.size(); ++i) {
            for(int c = 0; c< 26; ++c) {
                str[i] = 'a' + c;
                auto it = D.find(str);
                if(it != D.end()) {
                    D.erase(it);
                    q.emplace(StringWithDistance{str, f.distance +1});
                }
            }
            str[i] = f.candidate_string[i];
        }
        q.pop();
    }
    return -1;
}

int main() {
    unordered_set<string> dict = {"bat", "cot", "dog", "dag", "dot", "cat"};

    // Test 1
    string s1 = "cat";
    string t1 = "dog";
    int dist1 = TransformString(dict, s1, t1);
    cout << "The distance between " << s1 << " and " << t1 << " is: " << dist1 << endl;

    // Test 2
    string s2 = "bat";
    string t2 = "dot";
    int dist2 = TransformString(dict, s2, t2);
    cout << "The distance between " << s2 << " and " << t2 << " is: " << dist2 << endl;

    return 0;
}