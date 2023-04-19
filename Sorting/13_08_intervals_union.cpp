#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
    struct Endpoint
    {
        bool is_closed;
        int val;
    };

    Endpoint left, right;
};

vector<Interval> UnionOfIntervals(vector<Interval> intervals)
{
    if (intervals.empty())
    {
        return {};
    }

    sort(intervals.begin(), intervals.end(),
         [](const Interval &a, const Interval &b)
         {
             if (a.left.val != b.left.val)
             {
                 return a.left.val < b.left.val;
             }
             return a.left.is_closed && !b.left.is_closed;
         });
    vector<Interval> result;
    for (Interval i : intervals)
    {
        if (!result.empty() &&
            (i.left.val < result.back().right.val ||
             (i.left.val == result.back().right.val &&
              (i.left.is_closed || result.back().right.is_closed))))
        {
            if (i.right.val > result.back().right.val ||
                (i.right.val == result.back().right.val && i.right.is_closed))
            {
                result.back().right = i.right;
            }
        }
        else
        {
            result.emplace_back(i);
        }
    }
    return result;
}

int main()
{
    vector<Interval> intervals = {
        {{false, 7}, {true, 8}},
        {{true, 1}, {false, 3}},
        {{true, 2}, {true, 4}},
        {{true, 14}, {false, 15}},
        {{false, 4}, {true, 5}},
        {{false, 12}, {false, 14}},
        {{false, 5}, {false, 6}},
        {{true, 9}, {true, 10}},
        {{false, 10}, {true, 12}},
        {{true, 11}, {false, 11}},
        {{false, 15}, {true, 16}}};
    vector<Interval> result = UnionOfIntervals(intervals);
    for (Interval i : result)
    {
        cout << (i.left.is_closed ? "[" : "(") << i.left.val << ", " << i.right.val << (i.right.is_closed ? "]" : ")");
    }
    cout << endl;
    return 0;
}