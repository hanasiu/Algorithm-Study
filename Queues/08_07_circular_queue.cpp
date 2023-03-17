#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Queue {
    public:
    Queue(size_t capacity) {}
    explicit Queue(int capacity) : entries_(capacity) {}

    void Enqueue(int x) {
        if(num_queue_elements == entries_.size()) {
            rotate(entries_.begin(), entries_.begin() + head_, entries_.end());
            head_ = 0, tail_ = num_queue_elements;
            entries_.resize(entries_.size() * kScaleFactor);
        }

        entries_[tail_] = x;
        tail_ = (tail_ + 1) % entries_.size(), ++num_queue_elements;
    }

    int Dequeue() {
        --num_queue_elements;
        int result = entries_[head_];
        head_ = (head_ + 1) % entries_.size();
        return result;
    }

    int Size() const {
        return num_queue_elements;
    }

    int ArraySize() const {
        return entries_.size();
    }

    private:
    const int kScaleFactor = 2;
    int head_ = 0, tail_ = 0, num_queue_elements = 0;
    vector<int> entries_;
};

int main() {
    // Create a queue with initial capacity 3
    Queue q(3);

    // Add some elements to the queue
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    q.Enqueue(6);
    q.Enqueue(7);


    // Check the size of the queue
    cout << "Queue size: " << q.Size() << endl;
    cout << "Array size: " << q.ArraySize() << endl;
  
    // Dequeue some elements from the queue
    cout << q.Dequeue() << " ";
    cout << q.Dequeue() << " ";

    // Check the size of the queue again
    cout << "\nQueue size: " << q.Size() << endl;

    // Add some more elements to the queue
    q.Enqueue(5);
    q.Enqueue(6);

    // Dequeue the remaining elements from the queue
    while (q.Size() > 0) {
        cout << q.Dequeue() << " ";
    }

    // Check the size of the queue one last time
    cout << "\nQueue size: " << q.Size() << endl;

    return 0;
}