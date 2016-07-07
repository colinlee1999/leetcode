#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> m;
		unordered_map<int, int>::iterator it;
		vector<int> result;
		for (int i = 0; i < nums.size(); i++)
		{
			if ((it = m.find(target - nums[i])) != m.end())
			{
				result.push_back(it->second);
				result.push_back(i);
				break;
			}
			else
				m.insert(pair<int, int>(nums[i], i));
		}
		return result;
    }
};

int main()
{
	Solution s;
	cin.get();
}
