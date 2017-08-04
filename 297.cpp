#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <utility>

#include <cstdio>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string result = "[";
		if (root) {
			result += to_string(root->val);
			result += serialize(root->left);
			result += serialize(root->right);
		}
		result += "]";
		return result;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		pos = 0;
		return dfs(data);
	}

private:
	TreeNode* dfs(string& data) {
		TreeNode* result = NULL;
		if (pos < data.length()) {
			++pos;
			if (data[pos] != ']') {
				int val = 0;
				int sign = 1;
				if (data[pos] == '-') {
					sign = -1;
					++pos;
				}
				for (; pos < data.length(); ++pos) {
					if ('0' <= data[pos] && data[pos] <= '9') {
						val *= 10;
						val += data[pos] - '0';
					}
					else break;
				}
				result = new TreeNode(val * sign);
				result->left = dfs(data);
				result->right = dfs(data);
			}
			++pos;
		}
		return result;
	}

private:
	int pos;
};

int main()
{
	Solution s;
	cin.get();
}
