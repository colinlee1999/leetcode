#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <algorithm>
using namespace std;
#define INT_MIN (1<<31)
#define INT_MAX (~INT_MIN)

class Solution {
public:
	Solution()
	{
		factorials.push_back(1);
		for (int i = 1; i <= 10; i++)
			factorials.push_back(i*factorials.back());
	}

	int countNumbersWithUniqueDigits(int n) {
		if (n == 0) return 1;
		if (n == 1) return 10;
		int result = 10, count = 1;
		n = min(10, n);
		while (count < n)
		{
			result += A(9, count) * 9;
			count++;
		}
		return result;
	}

private:
	int A(int m, int n)
	{
		return factorials[m] / factorials[m - n];
	}

	vector<int> factorials;
};

int main()
{
	Solution s;
    cin.get();
}
