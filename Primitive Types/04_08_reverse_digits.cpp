#include <iostream>

using namespace std;

long long Reverse(int x) {
    long long result = 0;
    while(x) {
        result = result * 10 + x%10;
        x/=10;
    }
    return result;
}

int main() {
    int k = 1278321;
    long long result = Reverse(k);
    cout << result;
}