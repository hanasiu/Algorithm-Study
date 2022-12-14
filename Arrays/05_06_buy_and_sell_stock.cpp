#include <iostream>
#include <vector>

using namespace std;

double BuyAndSellStockOnce(const vector<double>& prices) {
	double min_price_so_far = numeric_limits<double>::max(), max_profit = 0;
	for (double price : prices) {
		double max_profit_sell_today = price - min_price_so_far;
		max_profit = std::max(max_profit, max_profit_sell_today);
		min_price_so_far = min(min_price_so_far, price);
	}
	return max_profit;
}

int main()
{
	vector<double> i = { 310, 315, 275,295,260,270,290,230,255,255 };
	cout << BuyAndSellStockOnce(i);

	return 0;
}
