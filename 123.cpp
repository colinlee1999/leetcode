#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int left = 0;
		int right = prices.size();
		int total_gain = 0;
		for (int mid = left + 2; mid <= right; mid++)
			total_gain = max(total_gain, _maxProfit(prices, left, mid) + _maxProfit(prices, mid, right));
		return total_gain;
	}

private:
	int _maxProfit(vector<int>& prices, int left, int right) {
		if (prices.size() < 2) return 0;
        int minimum = prices[left];
		int result = 0;
		for (int i = left + 1; i < right; i++)
		{
			if (prices[i] - minimum > result) result = prices[i] - minimum;
			if (prices[i] < minimum) minimum = prices[i];
		}
		return result;
    }
};

int main()
{
    Solution s;
    cin.get();
}
