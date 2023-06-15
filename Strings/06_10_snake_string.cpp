#include <iostream>

using namespace std;

string SnakeString(const string& s) {
    string result;
    cout << " ";//1
    for(int i = 1; i< s.size(); i+=4) {
        result += s[i];
        cout << s[i];
        cout << "   ";//3
    }
    cout << endl;
    for(int i = 0; i< s.size(); i+=2) {
        result += s[i];
        cout << s[i];
        cout << " ";//1
    }
    cout << endl;
    cout << "   ";//3
    for(int i = 3; i< s.size(); i+=4) {
        result += s[i];
        cout << s[i];
        cout << "   ";//3
    }
    return result;
}


int main() {
    string example = "Welcome#To#The#World!";
    string snake = SnakeString(example);
    return 0;
}
