#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2) return 0;
		prices.push_back(INT_MIN);
		int buy_price;
		int total_gain = 0;
		int status = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			switch (status)
			{
			case 0:
				if (prices[i] > prices[i - 1])
				{
					buy_price = prices[i - 1];
					status = 1;
				}
				break;
			case 1:
				if (prices[i] < prices[i - 1])
				{
					total_gain += prices[i - 1] - buy_price;
					status = 0;
				}
				break;
			default:
				break;
			}
		}
		prices.pop_back();
		return total_gain;
	}
};

int main()
{
	Solution s;
    cin.get();
}
