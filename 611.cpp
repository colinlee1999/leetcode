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
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

class Solution {
public:
	int triangleNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int start = 0;
		int nlen = nums.size();
		while (start < nlen && nums[start]== 0) {
			++start;
		}
		if (start == nlen) {
			return 0;
		}
		else {
			VI index(1001, -1);
			int last = -1;
			for (int i = start; i < nlen; ++i) {
				if (nums[i] != last) {
					last = nums[i];
					index[last] = i;
				}
			}
			last = -1;
			for (int i = 1000; i > 0; --i) {
				if (index[i] == -1) {
					index[i] = last;
				}
				else {
					last = index[i];
				}
			}
			int result = 0;
			for (int l = start; l < nlen; ++l) {
				for (int r = l + 2; r < nlen; ++r) {
					if (nums[l] == nums[r]) {
						result += r - l - 1;
					}
					else {
						int tmp = index[nums[r] - nums[l] + 1];
						if (tmp != -1) {
							if (l + 1 > tmp) {
								tmp = l + 1;
							}
							result += r - tmp;
						}
					}
				}
			}
			return result;
		}
	}
};

int main()
{
	Solution s;
	cin.get();
}
