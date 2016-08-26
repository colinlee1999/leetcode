#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> result;
		result.push_back(0);
		int cur = 1;
		int i = 1;
		while (i <= num)
		{
			for (int j = 0; j < cur; j++)
			{
				result.push_back(1 + result[j]);
				i++;
				if (i > num) break;
			}
			cur = i;
		}
		return result;
	}
};

int main()
{
    Solution s;
    cin.get();
}
