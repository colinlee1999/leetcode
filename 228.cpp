#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
		vector<string> result;
		if (nums.empty()) return result;
		nums.push_back(nums.back() + 2);
		int last = nums[0], count = 1;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] == nums[i - 1] + 1)
				count++;
			else
			{
				ostringstream os;
				if (count > 1)
					os << last << "->" << nums[i - 1];
				else
					os << last;
				result.push_back(os.str());
				last = nums[i];
				count = 1;
			}
		}

		return result;
	}
};

int main()
{
    Solution s;
    cin.get();
}
