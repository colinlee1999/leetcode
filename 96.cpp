#include "iostream"
#include "vector"
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int numTrees(int n) {
		if (n == 0) return 0;
		double result = 1;
		for (int i = n + n; i > n; i--)
		{
			result *= i;
			result /= (i - n);
		}
		result /= (n + 1);
		return (int)(result + 1e-6);
	}
};

int main()
{
	Solution s;
    cin.get();
}
