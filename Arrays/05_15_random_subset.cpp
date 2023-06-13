#include <vector>
#include <iostream>
#include <random>
#include <unordered_map>

using namespace std;

vector<int> RandomSubset(int n, int k)
{
    unordered_map<int, int> changed_elements;
    default_random_engine seed((random_device())());
    for (int i = 0; i < k; ++i)
    {
        int rand_idx = uniform_int_distribution<int>{i, n - 1}(seed);
        auto ptr1 = changed_elements.find(rand_idx);
        auto ptr2 = changed_elements.find(i);
        if (ptr1 == changed_elements.end() && ptr2 == changed_elements.end())
        {
            changed_elements[rand_idx] = i;
            changed_elements[i] = rand_idx;
        }
        else if (ptr1 == changed_elements.end() && ptr2 != changed_elements.end())
        {
            changed_elements[rand_idx] = ptr2->second;
            ptr2->second = rand_idx;
        }
        else if (ptr1 != changed_elements.end() && ptr2 == changed_elements.end())
        {
            changed_elements[i] = ptr1->second;
            ptr1->second = i;
        }
        else
        {
            int temp = ptr2->second;
            changed_elements[i] = ptr1->second;
            changed_elements[rand_idx] = temp;
        }
    }

    vector<int> result;
    for (int i = 0; i < k; ++i)
    {
        result.emplace_back(changed_elements[i]);
    }
    return result;
}

int main()
{
    vector<int> example = RandomSubset(100, 10);
    for (auto i : example)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}