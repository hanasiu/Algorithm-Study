#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Event {
    int start, finish;
};

struct Endpoint {
    int time;
    bool is_start;
};

int FindMaxSimultaneousEvents(const vector<Event>& A) {
    vector<Endpoint> E;
    for(const Event& event : A) {
        E.emplace_back(Endpoint{event.start, true});
        E.emplace_back(Endpoint{event.finish, false});
    }

    sort(E.begin(), E.end(), [](const Endpoint& a, const Endpoint& b) {
        return a.time != b.time ? a.time < b.time : (a.is_start && !b.is_start);
    });

    int max_num_simultaneous_events = 0, num_simultaneous_events = 0;
    for(const Endpoint& endpoint : E) {
        if(endpoint.is_start) {
            ++num_simultaneous_events;
            max_num_simultaneous_events =
            max(num_simultaneous_events, max_num_simultaneous_events);
        } else {
            --num_simultaneous_events;
        }
    }
    return max_num_simultaneous_events;
}

int main() {
    vector<Event> A = {{1, 5}, {2, 7}, {4, 5}, {6, 10}, {9, 17}, {11, 13}, {12, 15}, {14, 15}};
    int max_simultaneous_events = FindMaxSimultaneousEvents(A);
    cout << "Max number of simultaneous events: " << max_simultaneous_events << endl;
    return 0;
}