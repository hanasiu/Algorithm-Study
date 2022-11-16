#pragma once
#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

struct Student {
	bool operator<(const Student& that) const { return name < that.name; }

	string name;
	double grade_point_average;
};

void sortByName(vector<Student>* students) {
	sort((*students).begin(), (*students).end());
}

void sortByGPA(vector<Student>* students) {
	sort((*students).begin(), (*students).end(), [](const Student& a, const Student& b) {
		return a.grade_point_average >= b.grade_point_average;
		});
}

int main()
{
	
	return 0;
}
