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

typedef vector<int> VI;

class Solution {
public:
	int nextGreaterElement(int n) {
		VI digits = getDigits(n);
		reverse(digits.begin(), digits.end());
		nextPermutation(digits);
		int result = getNumber(digits);
		if (result <= n) {
			return -1;
		}
		else {
			return result;
		}
	}

private:
	int getNumber(VI& digits) {
		int result = 0;
		for (auto it : digits) {
			result = 10 * result + it;
		}
		return result;
	}

	VI getDigits(int n) {
		VI result;
		while (n > 9) {
			result.push_back(n % 10);
			n /= 10;
		}
		result.push_back(n);
		return result;
	}

	void nextPermutation(vector<int>& nums) {
		if (nums.size() <= 1) return;
		int pos = nums.size();
		for (int i = nums.size() - 1; i > 0; i--)
		{
			if (nums[i] > nums[i - 1])
			{
				pos = i - 1;
				break;
			}
		}
		if (pos == nums.size())
		{
			reverse(nums.begin(), nums.end());
			return;
		}
		for (int i = nums.size() - 1; i > pos; i--)
		{
			if (nums[i] > nums[pos])
			{
				int temp = nums[i];
				nums[i] = nums[pos];
				nums[pos] = temp;
				reverse(nums.begin() + pos + 1, nums.end());
				return;
			}
		}
		return;
	}
};

int main()
{
	Solution s;
	cin.get();
}
