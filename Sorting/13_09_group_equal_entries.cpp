#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Person
{
    int age;
    string name;
};

void GroupByAge(vector<Person> *people)
{
    unordered_map<int, int> age_to_count;
    for (const Person &p : *people)
    {
        ++age_to_count[p.age];
    }
    unordered_map<int, int> age_to_offset;
    int offset = 0;
    for (const auto &[age, count] : age_to_count)
    {
        cout << age << "!!!" << endl;
        age_to_offset[age] = offset;
        cout << "!@##@!" << offset << endl;
        offset += count;
    }

    while (!age_to_offset.empty())
    {
        auto from = age_to_offset.begin();
        cout << "*" << from->first << " " << from->second << endl; 
        auto to = age_to_offset.find((*people)[from->second].age);
        cout << "#" << to->first << " " << to->second << endl;
        swap((*people)[from->second], (*people)[to->second]);
        cout << "@@@@" << endl;

        --age_to_count[to->first];
        if (age_to_count[to->first] > 0)
        {
            ++to->second;
        }
        else
        {
            age_to_offset.erase(to);
        }
    }
}

int main() {
    vector<Person> i = {{14, "greg"}, {12, "john"}, {11, "andy"},
                        {13, "jim"},  {12, "phil"}, {13, "bob"}, {13, "chip"},
                        {14, "tim"}};
    GroupByAge(&i);
    for(const Person p : i) {
        cout << p.name << " " << p.age << " " << endl;
    }
     return 0;
}