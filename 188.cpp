#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		int plen = prices.size();
		if (plen == 0) return 0;
		k = min(plen / 2, k);
		if (k == plen / 2)
		{
			int profit = 0;
			for (int i = 1; i < plen; i++)
			{
				int diff = prices[i] - prices[i - 1];
				if (diff > 0)
					profit += diff;
			}
			return profit;
		}
		vector<int> sell(k + 1, 0);
		vector<int> not_sell(k + 1, 0);
		for (int i = 1; i < plen; i++)
		{
			vector<int> new_sell(k + 1, 0);
			vector<int> new_not_sell(k + 1, 0);
			int profit = prices[i] - prices[i - 1];
			for (int kk = 1; kk <= k; kk++)
			{
				new_sell[kk] = max(sell[kk] + profit, not_sell[kk - 1] + profit);
				new_not_sell[kk] = max(not_sell[kk], sell[kk]);
			}
			sell.swap(new_sell);
			not_sell.swap(new_not_sell);
		}
		return max(sell.back(), not_sell.back());
	}
};

int main()
{
    Solution s;
    cin.get();
}
