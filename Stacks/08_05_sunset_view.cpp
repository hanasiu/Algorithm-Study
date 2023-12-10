#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> ExamineBuildingsWithSunset(
    vector<int>::const_iterator sequence_begin,
        vector<int>::const_iterator& sequence_end
) {
    int building_idx = 0;
    struct BuildingWithHeight {
        int id, height;
    };
    stack<BuildingWithHeight> candidates;
    while (sequence_begin != sequence_end) {
        int building_height  = *sequence_begin++;
        while(!candidates.empty() && building_height >= candidates.top().height) {
            candidates.pop();
        }
        candidates.emplace(BuildingWithHeight{building_idx++, building_height});
    }

    vector<int> buildings_with_sunset;
    while(!candidates.empty()) {
        buildings_with_sunset.emplace_back(candidates.top().id);
        candidates.pop();
    }
    return buildings_with_sunset;
}



int main() {
    // Test case: Heights of buildings from east to west
    vector<int> buildingHeights = {10, 7, 12, 6, 8, 9};
    
    // Call the function with iterators
    vector<int>::const_iterator begin = buildingHeights.begin();
    vector<int>::const_iterator end = buildingHeights.end();
    
    vector<int> result = ExamineBuildingsWithSunset(begin, end);

    // Output the result
    cout << "Buildings with sunset view (from east to west): ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
