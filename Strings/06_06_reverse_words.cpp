#include <iostream>
#include <algorithm>

using namespace std;

void ReverseWords(string* s) {
    reverse((*s).begin(), (*s).end());

    size_t start = 0, finish;
    while((finish =  s->find(" ", start)) != string::npos) {
        reverse((*s).begin() + start, (*s).begin() + finish);
        start = finish + 1;
    }
    reverse((*s).begin() + start, (*s).end());
}

int main() {
    string k = "I want to read book";
    ReverseWords(&k);
    cout << k;
}