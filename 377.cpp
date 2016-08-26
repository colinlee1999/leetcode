#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
#include <stack>
#include <ctime>
#include <random>
using namespace std;

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<int> f(target + 1, 0);
		f[0] = 1;
		for (int i = 1; i <= target; i++)
		{
			for (auto it : nums)
				if (i - it >= 0)
					f[i] += f[i - it];
		}
		return f[target];
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(nums);
* vector<int> param_1 = obj.reset();
* vector<int> param_2 = obj.shuffle();
*/

int main()
{
    cin.get();
}
