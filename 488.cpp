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

struct ele {
	ele() {
		color = 0;
		num = 0;
	}

	ele(int c, int n) {
		color = c;
		num = n;
	}

	int color;
	int num;
};

class Solution {
public:
	int findMinStep(string board, string hand) {
		vector<ele> b = process(board);
		int blen = b.size();
		set<int> b_colors;
		for (auto it : b) {
			b_colors.insert(it.color);
		}
		vector<int> h;
		for (int i = 0; i < hand.length(); i++) {
			int cur_color = hand[i] - 'A';
			if (b_colors.find(cur_color) != b_colors.end()) {
				h.push_back(cur_color);
			}
		}
		vector<vector<int>> perh = permute(h);
		ans = 10;
		for (auto it : perh) {
			try_zuma(b, it, 0);
		}
		if (ans == 10) {
			return -1;
		}
		else {
			return ans;
		}
	}

private:
	void try_zuma(vector<ele> b, vector<int> & it, int depth) {
		if (depth >= ans || depth == it.size() || b.empty()) {
			if (b.empty() && depth < ans) {
				ans = depth;
			}
		}
		else {
			vector<int> pos = shoot(b, it[depth]);
			//for (auto it : pos) {
			//	cout << it << endl;
			//}
			if (!pos.empty()) {
				for (auto p : pos) {
					//cout << "ok" << endl;
					try_zuma(merge(b, p), it, depth + 1);
				}
			}
		}
	}

	vector<ele> merge(vector<ele> b, int p) {
		++b[p].num;
		//cout << "ok2" << endl;
		return do_merge(b);
	}

	vector<ele> do_merge(vector<ele> & b) {
		int blen = b.size();
		int pos = -1;
		for (int i = 0; i < blen; i++) {
			if (b[i].num >= 3) {
				pos = i;
				break;
			}
		}
		if (pos >= 0) {
			vector<ele> result;
			b[pos].num = 0;
			if (pos != 0 && pos + 1 != b.size() && b[pos - 1].color == b[pos + 1].color) {
				b[pos - 1].num += b[pos + 1].num;
				b[pos + 1].num = 0;
			}
			for (auto it : b) {
				if (it.num != 0) {
					result.push_back(it);
				}
			}
			return do_merge(result);
		}
		else {
			return b;
		}
	}

	vector<int> shoot(vector<ele> b, int color) {
		int blen = b.size();
		vector<int> result;
		for (int i = 0; i < blen; i++) {
			if (b[i].color == color) {
				result.push_back(i);
			}
		}
		return result;
	}

	vector<ele> process(string & board) {
		vector<ele> result;
		int last = 0;
		for (auto it : board) {
			if (last != it - 'A') {
				if (!result.empty() && result.back().num >= 3) {
					result.pop_back();
				}
				last = it - 'A';
				result.emplace_back(last, 1);
			}
			else {
				++result.back().num;
			}
		}
		return result;
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		result.push_back(nums);
		while (nextPermutation(nums))
			result.push_back(nums);
		return result;
	}

	bool nextPermutation(vector<int>& nums) {
		if (nums.size() <= 1) return false;
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
			return false;
		}
		for (int i = nums.size() - 1; i > pos; i--)
		{
			if (nums[i] > nums[pos])
			{
				int temp = nums[i];
				nums[i] = nums[pos];
				nums[pos] = temp;
				reverse(nums.begin() + pos + 1, nums.end());
				return true;
			}
		}
		return true;
	}

	int ans;
};

int main()
{
	Solution s;
	cout << s.findMinStep("WRRBBW", "RB") << endl;
	cin.get();
}
