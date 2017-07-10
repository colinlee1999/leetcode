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

#include <cstdio>
using namespace std;

typedef unordered_map<int, int> umap_i_i;

class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		umap_i_i umap;
		umap[0] = -1;
		int numZero = 0;
		int numOne = 0;
		int result = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == 0) {
				++numZero;
			}
			else {
				++numOne;
			}
			if (umap.find(numOne - numZero) != umap.end()) {
				result = max(result, i - umap[numOne - numZero]);
			}
			else {
				umap[numOne - numZero] = i;
			}
		}
		return result;
	}

private:
	int max(int a, int b) {
		if (a > b) return a;
		else return b;
	}
};

int main()
{
	Solution s;
	cin.get();
}
