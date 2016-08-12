#include "iostream"
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#define INT_MIN (1<<31)
#define INT_MAX (~INT_MIN)
using namespace std;

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), my_comp_func);
		ostringstream os;
		for (auto it = nums.rbegin(); it != nums.rend(); it++)
			os << *it;
		if (os.str()[0] == '0')
			return "0";
		return os.str();
	}

private:
	struct
	{
		bool operator()(const int & a, const int & b)
		{
			int l1 = 1, l2 = 1;
			long long ta = a, tb = b;
			while (ta > 9)
			{
				ta /= 10;
				l1++;
			}
			while (tb > 9)
			{
				tb /= 10;
				l2++;
			}
			if (l1 == l2) return a < b;
			stringstream os1, os2;
			os1 << a << b;
			os1 >> ta;
			os2 << b << a;
			os2 >> tb;
			return ta < tb;
		}
	} my_comp_func;
};

int main()
{
    cin.get();
}
