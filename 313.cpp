#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
	Solution()
	{
		series.push_back(1);
		heap.push_back(heap_element(0, 0, series));
	}

	int nthSuperUglyNumber(int n, vector<int>& primes) {
		for (auto pit : primes)
			heap.push_back(heap_element(0, pit, series));
		for (int i = (int)primes.size() / 2; i >= 1; i--)
			heap_filter_down(i);
		int count = 1;
		while (count < n)
		{
			if (series.back() < heap[1].val)
			{
				series.push_back(heap[1].val);
				count++;
			}
			++heap[1];
			heap_filter_down(1);
		}
		return series.back();
	}

private:
	struct heap_element
	{
		heap_element(int pos, int mul, vector<int> & series)
		{
			this->pos = pos;
			this->mul = mul;
			this->series = &series;
			this->val = (*(this->series))[pos] * mul;
		}

		heap_element& operator++()
		{
			this->pos++;
			this->val = (*(this->series))[this->pos] * mul;
			return *this;
		}

		int val;
		int pos;
		int mul;
		vector<int> * series;
	};

	void heap_filter_down(int pos)
	{
		int n = heap.size();
		while (pos + pos < n)
		{
			int next = pos + pos;
			if (next + 1 < n && heap[next + 1].val < heap[next].val)
				next++;
			if (heap[next].val < heap[pos].val)
				swap(heap[next], heap[pos]);
			else break;
			pos = next;
		}
	}

	vector<heap_element> heap;
	vector<int> series;
};

int main()
{
    Solution s;
	int myInt[] = { 2,3,5 };
	vector<int> v(myInt, myInt + sizeof(myInt) / sizeof(int));
	cout << s.nthSuperUglyNumber(62, v) << endl;
    cin.get();
}
