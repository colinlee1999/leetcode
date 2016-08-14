#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int nlen = nums.size();
		vector<int> result(nlen,1);
		for (int i = 1; i < nlen; i++)
			result[i] = result[i - 1] * nums[i - 1];
		int temp = 1;
		for (int i = nlen - 2; i >= 0; i--)
		{
			temp *= nums[i + 1];
			result[i] = result[i] * temp;
		}
		return result;
	}
};

int main()
{
    Solution s;
	cout << s.calculate("2-1+2") << endl;
    cin.get();
}
