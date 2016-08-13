#include "iostream"
#include "vector"
#include <set>
#include "map"
#include <algorithm>
using namespace std;
 
class Solution {
public:
	Solution()
	{
		heap.push_back(pair<int, int>(0, 0));
	}

	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>> result;
		if (buildings.empty())
			return result;
		
		int blen = buildings.size();
		vector<pair<int, int>> sorted_by_right;
		for (int i = 0; i < blen; i++)
		{
			sorted_by_right.push_back(pair<int, int>(buildings[i][1], i));
			pos_map.push_back(0);
		}
		sort(sorted_by_right.begin(), sorted_by_right.end());
		int left_pos = 0;
		int right_pos = 0;
		int last_height = 0;
		int vertical = -1;
		while (left_pos < blen || right_pos < blen)
		{
			if ((left_pos < blen && right_pos < blen && sorted_by_right[right_pos].first <= buildings[left_pos][0])
				|| left_pos == blen)
				vertical = sorted_by_right[right_pos].first;
			if ((left_pos < blen && right_pos < blen && sorted_by_right[right_pos].first >= buildings[left_pos][0])
				|| right_pos == blen)
				vertical = buildings[left_pos][0];
			//cout << "++++++++++++++" << endl;
			//cout << vertical << endl;
			while (right_pos < blen && sorted_by_right[right_pos].first == vertical)
			{
				//cout << "deleting..." << endl;
				heap_delete(pos_map[sorted_by_right[right_pos].second]);
				right_pos++;
			}
			while (left_pos < blen && buildings[left_pos][0] == vertical)
			{
				//cout << "inserting..." << endl;
				heap_insert(buildings[left_pos][2], left_pos);
				left_pos++;
			}
			//cout << "finish deleting and inserting" << endl;
			//for (int i = 1; i < heap.size(); i++)
			//	cout << heap[i].first << " ";
			//cout << endl;
			//for (int i = 1; i < heap.size(); i++)
			//	cout << heap[i].second << " ";
			//cout << endl;
			//for (int i = 0; i < blen; i++)
			//	cout << pos_map[i] << ' ';
			//cout << endl;
			if (heap.size()>1 && heap[1].first != last_height)
			{
				last_height = heap[1].first;
				result.push_back(pair<int, int>(vertical,last_height));
			}
			else if (heap.size() == 1 && 0 != last_height)
			{
				last_height = 0;
				result.push_back(pair<int, int>(vertical, last_height));
			}
		}
		return result;
	}

private:
	void heap_insert(int val, int pos)
	{
		pos_map[pos] = heap.size();
		heap.push_back(pair<int, int>(val, pos));
		heap_filter_up((int)heap.size() - 1);
	}

	void heap_delete(int pos)
	{
		//cout << "delete:\t" << pos << endl;
		heap_swap(pos, (int)heap.size() - 1);
		heap.pop_back();
		if (pos < heap.size())
			heap_filter_down(pos);
	}

	void heap_filter_up(int pos)
	{
		while (pos != 1)
		{
			if (heap[pos / 2].first < heap[pos].first)
			{
				heap_swap(pos, pos / 2);
				pos /= 2;
			}
			else break;
		}
	}

	void heap_filter_down(int pos)
	{
		while (pos + pos < (int)heap.size())
		{
			int next = pos + pos;
			if (next + 1 < (int)heap.size() && heap[next + 1].first > heap[next].first) next++;
			if (heap[next].first>heap[pos].first)
			{
				heap_swap(pos, next);
				pos = next;
			}
			else break;
		}
	}

	void heap_swap(int pos_1, int pos_2)
	{
		int p1 = heap[pos_1].second;
		int p2 = heap[pos_2].second;
		swap(pos_map[p1], pos_map[p2]);
		pair<int, int> x = heap[pos_1];
		heap[pos_1] = heap[pos_2];
		heap[pos_2] = x;
	}

	vector<pair<int, int>> heap;
	vector<int> pos_map;

	struct
	{
		bool operator()(const pair<int, int> & a, const pair<int, int> & b)
		{
			return a.first < b.first;
		}
	} my_comp_func;
};

int main()
{
    Solution s;
    cin.get();
}
