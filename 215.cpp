#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;
 
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		vector<int> heap(1, 0);
		for (int i = 0; i < k; i++)
			heap.push_back(nums[i]);
		for (int i = k / 2; i >= 1; i--)
			heap_filter_down(heap, i);
		for (int i = k; i < nums.size(); i++)
		{
			if (nums[i] > heap[1])
			{
				heap[1] = nums[i];
				heap_filter_down(heap, 1);
			}
		}
		return heap[1];
	}

	void heap_filter_down(vector<int> & heap, int i)
	{
		int n = heap.size() - 1;
		int x = heap[i];
		while (i + i <= n)
		{
			int next = i + i;
			if (i + i < n && heap[i + i + 1] < heap[i + i]) next++;
			if (heap[next] < x)
			{
				heap[i] = heap[next];
				i = next;
			}
			else break;
		}
		heap[i] = x;
	}
};

int main()
{
    Solution s;
    cin.get();
}
