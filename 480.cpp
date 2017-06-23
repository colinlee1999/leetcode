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

typedef long long ll;
typedef multiset<ll> msll;

class Solution {
public:
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		if (k == 1) {
			return vector<double>(nums.begin(), nums.end());
		}
		int nlen = nums.size();
		vector<int> pnum(nums.begin(), nums.begin() + k);
		sort(pnum.begin(), pnum.end());
		ll m2fold;
		int mid = k / 2;
		msll low, high;
		if (k & 1) {
			m2fold = (ll)pnum[mid] * 2;
			for (int i = 0; i < mid; ++i) {
				low.insert(pnum[i]);
				high.insert(pnum[k - 1 - i]);
			}
		}
		else {
			m2fold = (ll)pnum[mid] + (ll)pnum[mid - 1];
			for (int i = 0; i < mid; ++i) {
				low.insert(pnum[i]);
				high.insert(pnum[k - 1 - i]);
			}
		}
		vector<double> result;
		result.push_back(m2fold);
		for (int i = k; i < nlen; ++i) {
			if (k & 1 && nums[i - k] == m2fold / 2) {
				m2fold = *high.begin();
				high.erase(high.begin());
				m2fold *= 2;
			}
			else {
				if (low.find(nums[i - k]) != low.end()) {
					low.erase(low.find(nums[i - k]));
				}
				else {
					high.erase(high.find(nums[i - k]));
				}
			}
			if (less(nums[i], m2fold)) {
				low.insert(nums[i]);
			}
			else {
				high.insert(nums[i]);
			}
			if (low.size() != high.size()) {
				if (k & 1) {
					if (low.size() < high.size()) {
						low.insert(m2fold / 2);
						m2fold = *high.begin();
						high.erase(high.begin());
					}
					else {
						high.insert(m2fold / 2);
						m2fold = *low.rbegin();
						low.erase(--low.end());
					}
					m2fold *= 2;
				}
				else {
					ll t1, t2;
					if (low.size() < high.size()) {
						t1 = *high.begin();
						high.erase(high.begin());
						low.insert(t1);
						t2 = *high.begin();
					}
					else {
						t1 = *low.rbegin();
						low.erase(--low.end());
						high.insert(t1);
						t2 = *low.rbegin();
					}
					m2fold = t1 + t2;
				}
			}
			else if (!(k & 1)) {
				m2fold = *high.begin() + *low.rbegin();
			}
			result.push_back(m2fold);
		}
		for (int i = 0; i < result.size(); ++i) {
			result[i] /= 2;
		}
		return result;
	}

private:
	bool less(ll a, ll b) {
		return a + a < b;
	}
};

int main()
{
	Solution s;
	cin.get();
}
