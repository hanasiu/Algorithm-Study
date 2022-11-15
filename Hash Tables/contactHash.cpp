#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

struct contactList {
	//Equal function for hash.
	bool operator==(const contactList& that) const {
		return unordered_set<string>(names.begin(), names.end()) ==
			unordered_set<string>(that.names.begin(), that.names.end());
	}

	vector<string> names;
};

// Hash function for contactList
struct hashContactList {
	size_t operator()(const contactList& contacts) const {
		size_t hash_code = 0;
		for(const string& name : 
			unordered_set<string>(contacts.names.begin(), contacts.names.end())) {
			hash_code ^= std::hash<string>{}(name);
		}
		return hash_code;
	}
};

vector<contactList> mergeContactLists(const vector<contactList>& contacts) {
	unordered_set<contactList, hashContactList> unique_contacts(contacts.begin(), contacts.end());
	return {unique_contacts.begin(), unique_contacts.end()};
}

int main()
{
	
	return 0;
}
