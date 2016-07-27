#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>
#include <algorithm>
#define INT_MIN (1<<31)
#define INT_MAX (~(INT_MIN))
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int sumNumbers(TreeNode* root) {
		int sum = 0;
		if (root) dfs(root, 0, sum);
		return sum;
	}

private:
	void dfs(TreeNode * root,
		int cur_num,
		int & sum)
	{
		if (!root->left && !root->right)
			sum += 10 * cur_num + root->val;
		else
		{
			cur_num = cur_num * 10 + root->val;
			if (root->left) dfs(root->left, cur_num, sum);
			if (root->right) dfs(root->right, cur_num, sum);
		}
	}
};

int main()
{
    Solution s;
	unordered_set<string> v;
	// v.insert("hot");
	// v.insert("dog");
	// v.insert("cog");
	// v.insert("tot");
	// v.insert("hog");
	// v.insert("hop");
	// v.insert("pot");
	// v.insert("dot");
	// v.insert("lot");
	// v.insert("log");
	// s.findLadders("hit", "cog", v);
	v.insert("ted");
	v.insert("tex");
	v.insert("red");
	v.insert("tax");
	v.insert("tad");
	v.insert("den");
	v.insert("rex");
	v.insert("pee");
	s.findLadders("red", "tax", v);
    cin.get();
}
