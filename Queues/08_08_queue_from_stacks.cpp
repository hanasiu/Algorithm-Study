#include <iostream>
#include <stack>

using namespace std;

class Queue
{
public:
    void Enqueue(int x)
    {
        enqueue_.push(x);
    }
    int Dequeue()
    {
        if (dequeue_.empty())
        {
            while (!enqueue_.empty())
            {
                dequeue_.push(enqueue_.top());
                enqueue_.pop();
            }
        }
        int result = dequeue_.top();
        dequeue_.pop();
        return result;
    }

    stack<int> enqueue_, dequeue_;
};

int main() {
    Queue a;
    int i = 0;
    while(i++<10) {
        a.Enqueue(i);
    }
    cout << a.Dequeue() << endl;
    
    return 0;
}