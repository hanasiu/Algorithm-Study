#include <iostream>
#include <unordered_map>

using namespace std;

bool IsLetterConstructibleFromMagazine(const string& letter_text,
	const string& magazine_text) {
	unordered_map<char, int> char_frequency_for_letter;
	
	for (char c : letter_text) {
		++char_frequency_for_letter[c];
	}

	for (char c : magazine_text) {
		auto it = char_frequency_for_letter.find(c);
		if (it != char_frequency_for_letter.cend()) {
			--(it->second);
			if (it->second == 0) {
				char_frequency_for_letter.erase(it);
				if (char_frequency_for_letter.empty()) {
					break;
				}
			}
		}
	}
	return char_frequency_for_letter.empty();
}

int main()
{
	string i = "asdffdsa";
	string j = "fdsaasdf";
    cout << IsLetterConstructibleFromMagazine(i, j);
	return 0;
}
