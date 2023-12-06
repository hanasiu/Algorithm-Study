#include <iostream>
#include <numeric>


using namespace std;


int SSDecodeColID(const string& col) {
    return accumulate(col.begin(), col.end(), 0, [](int result, char c) {
        return result * 26 + c - 'A' + 1;
    });
}


int main()
{

    cout << SSDecodeColID("ABC") << endl;
    cout << SSDecodeColID("Z") << endl;
    cout << SSDecodeColID("AZ") << endl;
    cout << SSDecodeColID("ZZ") << endl;

	return 0;
}
