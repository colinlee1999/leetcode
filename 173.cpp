#include "iostream"
#include <vector>
#include <unordered_map>
#include <algorithm>
#define INT_MIN (1<<31)
#define INT_MAX (~INT_MIN)
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		TreeNode * p = root;
		while (p)
		{
			s.push(p);
			p = p->left;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return !s.empty();
	}

	/** @return the next smallest number */
	int next() {
		TreeNode * p = s.top();
		int result = p->val;
		s.pop();
		p = p->right;
		while (p)
		{
			s.push(p);
			p = p->left;
		}
		return result;
	}

private:
	stack<TreeNode *> s;
};

int main()
{
    cin.get();
}
