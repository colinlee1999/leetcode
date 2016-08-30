#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <algorithm>
#include <ctime>
using namespace std;
#define INT_MIN (1<<31)
#define INT_MAX (~INT_MIN)

class Solution {
public:
	Solution()
	{
		srand(time(0));
	}

	void wiggleSort(vector<int>& nums) {
		int nlen = nums.size();
		if (nlen <= 1) return;
		double median;
		if (nlen & 1)
			median = quickselect(nums, 0, nlen, nlen / 2);
		else
		{
			median = quickselect(nums, 0, nlen, nlen / 2) + quickselect(nums, 0, nlen, nlen / 2 - 1);
			median /= 2;
		}
		int stored_index = 1;
		for (int i = 0; i < nlen; i++)
			if (i & 1)
			{
				if (i >= stored_index && nums[i] > median)
				{
					swap(nums[i], nums[stored_index]);
					stored_index += 2;
				}
			}
			else
			{
				while (nums[i] > median)
				{
					swap(nums[i], nums[stored_index]);
					stored_index += 2;
				}
			}
		stored_index = (nlen & 1) ? (nlen - 1) : (nlen - 2);
		for (int i = nlen - 1; i >= 0; i--)
			if (i & 1)
			{
				while (nums[i] < median)
				{
					swap(nums[i], nums[stored_index]);
					stored_index -= 2;
				}
			}
			else
			{
				if (i <= stored_index && nums[i] < median)
				{
					swap(nums[i], nums[stored_index]);
					stored_index -= 2;
				}
			}
	}

private:
	int partition(vector<int> & nums, int left, int right, int pivot_index)
	{
		int pivot_value = nums[pivot_index];
		swap(nums[pivot_index], nums[right - 1]);
		int store_index = left;
		for (int i = left; i < right - 1; i++)
			if (nums[i] < pivot_value)
			{
				swap(nums[store_index], nums[i]);
				store_index++;
			}
		swap(nums[store_index], nums[right - 1]);
		return store_index;
	}

	int quickselect(vector<int> & nums, int left, int right, int select_index)
	{
		if (left + 1 == right)
			return nums[left];
		int pivot_index = ((double)rand() / RAND_MAX)*(right - left) + left;
		pivot_index = min(pivot_index, right - 1);
		pivot_index = partition(nums, left, right, pivot_index);
		if (pivot_index == select_index)
			return nums[pivot_index];
		if (select_index < pivot_index)
			return quickselect(nums, left, pivot_index, select_index);
		else
			return quickselect(nums, pivot_index + 1, right, select_index);
	}
};

int main()
{
	Solution s;
	// int myInt[] = { 1,5,1,1,6,4 };
	int myInt[] = { 2,3,3,2,2,2,1,1 };
	// int myInt[] = { 1 };
	vector<int> v(myInt, myInt + sizeof(myInt) / sizeof(int));
	s.wiggleSort(v);
	for (auto it : v)
		cout << it << ' ';
	cout << endl;
    cin.get();
}
