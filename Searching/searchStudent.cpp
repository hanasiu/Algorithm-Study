#pragma once
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Student {
	string name;
	double grade_point_average;
};

auto compGPA = [](const Student& a, const Student& b) { //comp(element, target)
	if (a.grade_point_average != b.grade_point_average) {
		return a.grade_point_average > b.grade_point_average; // element가 target보다 크면 true
	}
	return a.name < b.name; // target의 이름이 더 크면 true
};

bool searchStudent(
	const vector<Student>& students, const Student& target,
	decltype(compGPA)) {
	return binary_search(students.begin(), students.end(), target, compGPA);
};

int main()
{
	Student a;
	a.name = "kim";
	a.grade_point_average = 10;
	Student b;
	b.name = "sim";
	b.grade_point_average = 11;
	Student c;
	c.name = "cim";
	c.grade_point_average = 14;
	Student d;
	d.name = "dim";
	d.grade_point_average = 19;
	Student f;
	f.name = "fim";
	f.grade_point_average = 25;
	vector<Student> i = { f, d, c, b, a };

	cout << searchStudent(i, d, compGPA);
	return 0;
}
