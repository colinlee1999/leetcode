#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		int first_available, current_processing, last_number, count;
		first_available = current_processing = 1;
		last_number = nums.front();
		count = 1;
		while (current_processing < nums.size())
		{
			if (nums[current_processing] != last_number)
			{
				last_number = nums[current_processing];
				nums[first_available++] = last_number;
				count = 1;
			}
			else
			{
				if (count < 2)
				{
					count++;
					nums[first_available++] = last_number;
				}
			}
			current_processing++;
		}
		nums.resize(first_available);
		return nums.size();
    }
};

int main()
{
    cin.get();
}
