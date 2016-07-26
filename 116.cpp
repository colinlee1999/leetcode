#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
#include <algorithm>
using namespace std;

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root) return;
		vector<TreeLinkNode *> v;
		dfs(root, 1, v);
	}

private:
	void dfs(TreeLinkNode * root,
		int depth,
		vector<TreeLinkNode *> & v)
	{
		if (depth > v.size())
			v.push_back(root);
		else
		{
			v[depth - 1]->next = root;
			v[depth - 1] = root;
		}
		if (root->left) dfs(root->left, depth + 1, v);
		if (root->right) dfs(root->right, depth + 1, v);
	}
};

int main()
{
	Solution s;
    cin.get();
}
