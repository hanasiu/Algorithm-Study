#include <vector>
#include <iostream>
#include <numeric>
#include <random>

using namespace std;

void RandomSampling(int k, vector<int>* A_ptr) {
	vector<int>& A = *A_ptr;
	default_random_engine seed((random_device())());
	for (int i = 0; i < k; ++i) {
		swap(A[i], A[uniform_int_distribution<int>{
			i, static_cast<int>(A.size()) - 1}(seed)]);
	}
}

vector<int> ComputeRandomPermutation(int n) {
    vector<int> permutation(n);
    iota(permutation.begin(), permutation.end(), 0);
    RandomSampling(n, & permutation);
    return permutation;
}

int main() {
    vector<int> k = ComputeRandomPermutation(10);
    for(auto j : k) {
        cout << j << " ";
    }
    cout << endl;
    return 0;
}