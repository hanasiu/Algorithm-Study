#include <iostream>
#include <vector>
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

int main()
{
	vector<int> i = { 1,2,3,4,5,6, };
	RandomSampling(3, &i);
	for (auto k : i) {
		cout << k << endl;
	}
	
	return 0;
}
