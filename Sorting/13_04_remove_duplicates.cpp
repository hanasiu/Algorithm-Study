#include <iostream>
#include <algorithm>

using namespace std;

struct Name {
    bool operator==(const Name& that) const {
        return first_name == that.first_name;
    }

    bool operator<(const Name& that) const {
        return first_name != that.first_name ? first_name < that.first_name :
        last_name < that.last_name;
    }

    string first_name, last_name;
};

void EliminateDuplicate(vector<Name>* names) {
    sort(begin(*names), end(*names));

    names->erase(unique(begin(*names), end(*names)), end(*names));
}

int main() {
    // Create a vector of Name objects
    vector<Name> names = {
        {"John", "Doe"},
        {"Jane", "Doe"},
        {"John", "Smith"},
        {"Alice", "Johnson"},
        {"John", "Cake"}  // Duplicate
    };

    // Print the original vector
    cout << "Original Names:" << endl;
    for (const auto& name : names) {
        cout << name.first_name << " " << name.last_name << endl;
    }

    // Eliminate duplicates
    EliminateDuplicate(&names);

    // Print the modified vector without duplicates
    cout << "\nNames After Eliminating Duplicates:" << endl;
    for (const auto& name : names) {
        cout << name.first_name << " " << name.last_name << endl;
    }

    return 0;
}