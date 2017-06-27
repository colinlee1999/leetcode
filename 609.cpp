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

typedef vector<string> VS;
typedef vector<VS> VVS;

typedef unordered_map<string, VS>umap_s_VS;

class Solution {
public:
	vector<vector<string>> findDuplicate(vector<string>& paths) {
		umap_s_VS umap;
		for (auto s : paths) {
			VS tmp = split(s);
			string root = tmp[0];
			if (root.back() != '/') {
				root += "/";
			}
			for (int i = 1; i < tmp.size(); i++) {
				int l = tmp[i].find('(');
				int r = tmp[i].find(')');
				string content = tmp[i].substr(l + 1, r - l - 1);
				if (umap.find(content) != umap.end()) {
					umap[content].push_back(root + tmp[i].substr(0, l));
				}
				else {
					umap[content] = VS(1, root + tmp[i].substr(0, l));
				}
			}
		}
		VVS result;
		for (auto it : umap) {
			if (it.second.size() > 1) {
				result.push_back(it.second);
			}
		}
		return result;
	}

private:
	VS split(string & s) {
		s = s + " ";
		VS result;
		int i = 0;
		int last = 0;
		while (i < s.length()) {
			if (s[i] == ' ') {
				result.push_back(s.substr(last, i - last));
				last = i + 1;
			}
			++i;
		}
		return result;
	}
};

int main()
{
	Solution s;
	cin.get();
}
