#include <iostream>

using namespace std;

int SearchEntryEqualToItsIndex(const vector<int>& A) {
    int left = 0, right = A.size() - 1;
    while(left <= right) {
        int mid = left + ((right - left )/ 2);
        if(int difference = A[mid] - mid; difference == 0) {
            return mid;
        } else if (difference > 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    // Test the function with a sample vector
    vector<int> sampleVector = {-10, -5, 0, 3, 4, 9, 12, 17}; // Replace this with your own vector

    int result = SearchEntryEqualToItsIndex(sampleVector);

    // Print the result
    if (result != -1) {
        cout << "Found at index: " << result << endl;
    } else {
        cout << "No entry found where value is equal to its index." << endl;
    }

    return 0;
}