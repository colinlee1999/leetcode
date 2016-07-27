#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0) return 0;
		vector<int> sell(prices.size(), 0), buy(prices.size(), 0);
		int best_buy_price = prices.front();
		for (int i = 1; i < (int)prices.size(); i++)
		{
			sell[i] = max(sell[i - 1], prices[i] - best_buy_price);
			best_buy_price = min(best_buy_price, prices[i]);
		}
		int best_sell_price = prices.back();
		for (int i = (int)prices.size() - 2; i >= 0; i--)
		{
			buy[i] = max(buy[i + 1], best_sell_price - prices[i]);
			best_sell_price = max(best_sell_price, prices[i]);
		}
		int total_gain = max(sell[(int)prices.size() - 1], buy[0]);
		for (int i = 0; i < (int)prices.size() - 1; i++)
			total_gain = max(total_gain, sell[i] + buy[i + 1]);
		return total_gain;
	}
};

int main()
{
    Solution s;
	vector<int> v;
	s.maxProfit(v);
    cin.get();
}
