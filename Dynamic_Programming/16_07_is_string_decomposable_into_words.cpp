#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<string> DecomposeIntoDictionaryWords(
    const string& domain, const unordered_set<string>& dictionary) {
    vector<int> last_length(domain.size(), -1);
    for(int i = 0; i<domain.size(); ++i) {
        if(dictionary.count(domain.substr(0, i+1))) {
            last_length[i] = i+1;
            continue;
        }

        for(int j = 0; j<i; ++j) {
        if(last_length[j] != -1 && dictionary.count(domain.substr(j+1, i-j))) {
            last_length[i] = i-j;
            break;
        }
    }
    }

    vector<string> decompositions;
    if(last_length.back() != -1) {
        int idx = domain.size() -1;
        while(idx>=0) {
            decompositions.emplace_back(
                domain.substr(idx+1-last_length[idx], last_length[idx]));
                idx-=last_length[idx];
        }
        reverse(decompositions.begin(), decompositions.end());
    }
    return decompositions;
}


int main() {
    string i = "amanaplanetcanal";
    unordered_set<string> dictionary = {"a", "am", "an", "planet", "canal"};
    vector<string> k = DecomposeIntoDictionaryWords(i, dictionary);
    for(auto j : k) {
        cout << j << endl;
    }
    return 0;
}