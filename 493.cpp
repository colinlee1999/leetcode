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

typedef long long ull;

class Solution {
public:
	int reversePairs(vector<int>& nums) {
		vector<ull> nums2(nums.begin(), nums.end());
		int nlen = nums2.size();
		count = 0;
		merge_sort(0, nlen, nums2);
		return count;
	}
private:
	void merge_sort(int l, int r, vector<ull> & nums) {
		if (l + 1 < r) {
			int mid = (l + r) / 2;
			merge_sort(l, mid, nums);
			merge_sort(mid, r, nums);
			merge(l, r, mid, nums);
		}
	}

	void merge(int l, int r, int mid, vector<ull> & nums) {
		vector<ull> vl(nums.begin() + l, nums.begin() + mid);
		vector<ull> vr(nums.begin() + mid, nums.begin() + r);
		vector<ull> re(nums.begin() + l, nums.begin() + r);
		for (int i = 0; i < vr.size(); ++i) {
			vr[i] *= 2;
		}
		try_merge(vl, vr, re, true);
		for (int i = 0; i < vr.size(); ++i) {
			vr[i] /= 2;
		}
		try_merge(vl, vr, re, false);

		auto it = nums.begin() + l;
		for (int i = 0; i < re.size(); ++i, ++it) {
			*it = re[i];
		}
	}

	void try_merge(vector<ull> & vl, vector<ull> & vr, vector<ull> & re, bool flag) {
		int l = 0;
		int r = 0;
		int vllen = vl.size();
		int vrlen = vr.size();
		int i = 0;
		while (l < vllen && r < vrlen) {
			if (vl[l] <= vr[r]) {
				re[i] = vl[l];
				++l;
			}
			else {
				if (flag) {
					count += vllen - l;
				}
				re[i] = vr[r];
				++r;
			}
			++i;
		}
		while (l < vllen) re[i++] = vl[l++];
		while (r < vrlen) re[i++] = vr[r++];
	}

	int count;
};

int main()
{
	Solution s;
	cin.get();
}
