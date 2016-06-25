#include "iostream"
#include "vector"
#include "set"
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> set;
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
		{
			set.insert(*it);
		}
		if (nums.size() != set.size()) return true;
		return false;
    }
};

int main()
{
    Solution s;
    cin.get();
}
