#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		if (prices.size() == 0) return 0;
        int minimum = prices[0];
		int result = 0;
		for (vector<int>::iterator it = prices.begin() + 1; it != prices.end(); ++it)
		{
			if (*it - minimum > result) result = *it - minimum;
			if (*it < minimum) minimum = *it;
		}
		return result;
    }
};

int main()
{
    Solution s;
    cin.get();
}
