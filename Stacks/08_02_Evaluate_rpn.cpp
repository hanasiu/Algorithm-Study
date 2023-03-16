#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
#include <unordered_map>
#include <functional>
#include <string>

using namespace std;

int Evaluate(const string& expression) {
    stack<int> intermediate_results;
    stringstream ss(expression);
    string token;
    const char kDelimiter = ',';
    const unordered_map<string, function<int(int, int)>> kOperators = {
        {"+", [](int x,int y) -> int { return x + y; }},
        {"-", [](int x,int y) -> int { return x - y; }},
        {"*", [](int x,int y) -> int { return x * y; }},
        {"/", [](int x,int y) -> int { return x / y; }}};

        while(getline(ss, token, kDelimiter)) {
            if(kOperators.count(token)) {
                const int y = intermediate_results.top();
                intermediate_results.pop();
                const int x = intermediate_results.top();
                intermediate_results.pop();
                intermediate_results.emplace(kOperators.at(token)(x,y));
            } else {
                intermediate_results.emplace(stoi(token));
            }
        }
        return intermediate_results.top();
    }

int main() {
    string k = "3,4,+,2,*,1,+,3,/";
    int i = Evaluate(k);
    cout << i << endl;;
}