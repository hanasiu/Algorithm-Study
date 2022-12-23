#include <iostream>
#include <vector>
#include <array>

using namespace std;

int ChangeMaking(int cents) {
	const array<int, 6> kCoins = { 100,50,25,10,5,1 };
	int num_coins = 0;
	for (int coin : kCoins) {
		num_coins += cents / coin;
		cents %= coin;
	}
	return num_coins;
}

int main()
{
	cout << ChangeMaking(668);

	return 0;
}
