#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
#include <stack>
#include <ctime>
#include <random>
using namespace std;

class Solution {
public:
	Solution()
	{
		heap.push_back(heap_element(0, 0));
	}

	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		for (auto it : nums)
		{
			if (m.count(it))
				m[it]++;
			else m[it] = 1;
		}
		int count = 0;
		for (auto mit : m)
		{
			count++;
			if (count == k + 1)
			{
				for (int i = k / 2; i >= 1; i--)
					heap_filter_down(i);
			}
			if (count > k)
			{
				if (mit.second > heap[1].freq)
				{
					heap[1] = heap_element(mit.second, mit.first);
					heap_filter_down(1);
				}
			}
			else
				heap.push_back(heap_element(mit.second, mit.first));
		}
		vector<int> result;
		for (int i = 1; i < heap.size(); i++)
			result.push_back(heap[i].num);
		return result;
	}

private:
	struct heap_element
	{
		heap_element(int freq, int num)
		{
			this->num = num;
			this->freq = freq;
		}

		int freq;
		int num;
	};

	vector<heap_element> heap;

	void heap_filter_down(int pos)
	{
		int n = heap.size();
		while (pos + pos < n)
		{
			int next = pos + pos;
			if (next + 1 < n && heap[next + 1].freq < heap[next].freq) next++;
			if (heap[next].freq < heap[pos].freq)
				swap(heap[next], heap[pos]);
			else
				break;
			pos = next;
		}
	}
};

int main()
{
    cin.get();
}
