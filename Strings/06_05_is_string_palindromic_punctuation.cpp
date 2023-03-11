#include <iostream>
#include <vector>

using namespace std;

bool IsPalindrome(const string &s)
{
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
        while (!isalnum(s[i]) && i < j)
        {
            ++i;
        }
        while (!isalnum(s[j]) && i < j)
        {
            --j;
        }
        if (tolower(s[i++]) != tolower(s[j--]))
        {
            return false;
        }
    }
    return true;
}

int main() {
    string k = "A man, a plan, a canal, Panama.";
    string i = "Able was I, ere I saw Elba!";
    if(IsPalindrome(k)) cout << k << " is para.." << endl;
    if(IsPalindrome(i)) cout << i << "is para.." << endl;
}
