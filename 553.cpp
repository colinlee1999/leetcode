#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <utility>
using namespace std;

class Solution {
public:
	string optimalDivision(vector<int>& nums) {
		ostringstream os;
		os << nums[0];
		if (nums.size() <= 2) {
			if (nums.size() > 1) 
				os << "/" << nums[1];
			return os.str();
		}
		os << "/";
		os << "(";
		os << nums[1];
		for (int i = 2; i < nums.size(); ++i)
			os << "/" << nums[i];
		os << ")";
		return os.str();
	}
};

int main()
{
	Solution s;
	cin.get();
}
