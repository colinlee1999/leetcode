#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
#include <stack>
#include <deque>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int left = 0;
		int right = (int)numbers.size() - 1;
		while (numbers[left] + numbers[right] != target)
		{
			if (numbers[left] + numbers[right] < target) left++;
			else right--;
		}
		vector<int> result;
		result.push_back(left + 1);
		result.push_back(right + 1);
		return result;
	}
};

int main()
{
    Solution s;
	cout << s.countDigitOne(199) << endl;
    cin.get();
}
