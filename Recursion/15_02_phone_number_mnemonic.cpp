#include <iostream>

using namespace std;

const int kNumTelDigits = 10;

const array<string, kNumTelDigits> kMapping = {{"0", "1", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"}};

void PhoneMnemonicHelper(const string &phone_number, int digit, string *partial_mnemonic, vector<string> *mnemonics)
{
    if (digit == size(phone_number))
    {
        mnemonics->emplace_back(*partial_mnemonic);
    }
    else
    {
        for (char c : kMapping[phone_number[digit] - '0'])
        {
            (*partial_mnemonic)[digit] = c;
            PhoneMnemonicHelper(phone_number, digit + 1, partial_mnemonic, mnemonics);
        }
    }
}

vector<string> PhoneMnemonic(const string &phone_number)
{
    vector<string> mnemonics;
    string partial_mnemonic(size(phone_number), 0);
    string *i = &partial_mnemonic;
    PhoneMnemonicHelper(phone_number, 0, i, &mnemonics);
    return mnemonics;
}

int main()
{
    // Test the function
    string phone_number = "2345";
    vector<string> mnemonics = PhoneMnemonic(phone_number);
    int count = 0;
    // Print the generated mnemonics
    for (const string &mnemonic : mnemonics)
    {
        cout << mnemonic << endl;
        cout << ++count << endl;
    }

    return 0;
}