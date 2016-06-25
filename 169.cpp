#include "iostream"
#include "vector"
#include "set"
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result;
        int count=0;
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
		{
			if (count == 0)
			{
				result = *it;
				count++;
			}
			else
			{
				if (*it == result) count++;
				else count--;
			}
		}
		return result;
    }
};

int main()
{
    Solution s;
    cin.get();
}
