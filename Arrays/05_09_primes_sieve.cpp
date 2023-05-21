#include <deque>
#include <vector>
#include <iostream>

using namespace std;

vector<int> GeneratePrimes(int n) {
    vector<int> primes;
    deque<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;

    for(int p = 2; p<=n; ++p) {
        if(is_prime[p]) {
            primes.emplace_back(p);
            for(int i = p*2; i<=n; i+=p) {
                is_prime[i] = false;
            }
        }
    }
    return primes;
}

vector<int> GeneratePrimes2(int n) {
    if(n<2) {
        return {};
    }
    const int size = floor(0.5*(n-1)) + 1;
    vector<int> primes;
    primes.emplace_back(2);
    deque<bool> is_prime(size, true);

    for(int i = 0; i< size; ++i) {
        if(is_prime[i]) {
            int p = (i*2) +3;
            primes.emplace_back(p);
            for(long long j = 2LL* i * i + 6*i+3; j< size; j+=p) {
                is_prime[j] = false;
            } 
        }
    }
    return primes;
}

int main() {
    vector<int> example = GeneratePrimes2(50);
    for(auto i : example) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
