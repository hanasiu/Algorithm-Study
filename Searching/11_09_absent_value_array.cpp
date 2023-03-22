#include <iostream>
#include <vector> 
#include <bitset>

using namespace std;

int FindMissingElement(vector<int>::const_iterator stream_begin,
const vector<int>::const_iterator& stream_end) {
    const int kNumBucket = 1 << 16;
    vector<size_t>counter(kNumBucket, 0);
    vector<int>::const_iterator stream_begin_copy = stream_begin;
    while(stream_begin != stream_end) {
        int upper_part_x = *stream_begin >> 16; //**
        ++counter[upper_part_x];
        ++stream_begin;
    }

    const int kBucketCapacity = 1<<16;
    int candidate_bucket = 0;
    for(int i = 0; i< kNumBucket; ++i) {
        if(counter[i] < kBucketCapacity) {
            candidate_bucket = i;
            break;
        }
    }

    bitset<kBucketCapacity> candidates;
    stream_begin = stream_begin_copy;
    while(stream_begin != stream_end) {
        int x = *stream_begin++;
        int upper_part_x = x>>16; 
        if(candidate_bucket == upper_part_x) {
            int lower_part_x = ((1<<16) -1) & x;
            candidates.set(lower_part_x);
        }
    }

    for(int i = 0; i<kBucketCapacity; ++i) {
        if(candidates[i] == 0) {
            return (candidate_bucket << 16) | i;//**
        }
    }

    return -1;
}

int main() {
    // Create a vector of 2^20 elements with a missing element
    vector<int> stream;
    for(int i=0; i<(1<<20); i++) {
        if(i != (1<<16)) {
            stream.push_back(i);
        }
    }

    // Find the missing element
    int missing_element = FindMissingElement(stream.begin(), stream.end());

    // Check if the result is correct
    if(missing_element == (1<<16)) {
        cout << "Test passed: found missing element " << missing_element << endl;
    } else {
        cout << "Test failed: expected " << (1<<16) << ", got " << missing_element << endl;
    }

    return 0;
}