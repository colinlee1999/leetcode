#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
#include <stack>
#include <deque>
using namespace std;

class Solution {
public:
	int nthUglyNumber(int n) {
		int p2, p3, p5;
		p5 = p2 = p3 = 0;
		vector<long long> result;
		result.push_back(1);
		while (result.size() < n)
		{
			int temp;
			if (result[p2] * 2 <= result[p3] * 3 && result[p2] * 2 <= result[p5] * 5)
			{
				temp = result[p2] * 2;
				p2++;
			}
			else if (result[p3] * 3 <= result[p2] * 2 && result[p3] * 3 <= result[p5] * 5)
			{
				temp = result[p3] * 3;
				p3++;
			}
			else if (result[p5] * 5 <= result[p2] * 2 && result[p5] * 5 <= result[p3] * 3)
			{
				temp = result[p5] * 5;
				p5++;
			}
			if (temp > result.back())
				result.push_back(temp);
		}
		return result[n - 1];
	}
};

int main()
{
    Solution s;
    cin.get();
}
