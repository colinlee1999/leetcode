#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int plen = prices.size();
		if (plen < 2) return 0;
		vector<int> sell(plen, 0), not_sell(plen, 0);
		sell[1] = max(0, prices[1] - prices[0]);
		for (int i = 2; i < plen; i++)
		{
			int diff = prices[i] - prices[i - 1];
			sell[i] = max(sell[i - 1], not_sell[i - 2]) + diff;
			not_sell[i] = max(sell[i - 1], not_sell[i - 1]);
		}
		return max(sell.back(), not_sell.back());
	}
};

int main()
{
    Solution s;
    cin.get();
}
