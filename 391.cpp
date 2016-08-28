#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <algorithm>
using namespace std;
#define INT_MIN (1<<31)
#define INT_MAX (~INT_MIN)

struct ele
{
	ele(int bottom, int right, int top)
	{
		this->bottom = bottom;
		this->top = top;
		this->right = right;
	}

	ele(const ele & item)
	{
		this->bottom = item.bottom;
		this->top = item.top;
		this->right = item.right;
	}
	
	int bottom;
	int top;
	int right;
};

class Solution {
public:
	bool isRectangleCover(vector<vector<int>>& rectangles) {
		int rlen = rectangles.size();
		sort(rectangles.begin(), rectangles.end(), my_comp_func);
		vector<pair<int, int>> sorted_by_right;
		for (int i = 0; i < rlen; i++)
			sorted_by_right.push_back(pair<int, int>(rectangles[i][2],i));
		sort(sorted_by_right.begin(), sorted_by_right.end(), my_comp_func_2);
		int left_pos = 0;
		int right_pos = 0;
		int vertical = 0;
		bool mark_left, mark_right;
		map<int, ele> m; // bottom, top, right
		int round = 0;
		bool finished = false;
		while (left_pos < rlen || right_pos < rlen)
		{
			round++;
			mark_left = mark_right = false;
			if (left_pos == rlen)
				mark_right = true;
			else
			{
				if (sorted_by_right[right_pos].first >= rectangles[left_pos][0])
					mark_left = true;
				if (sorted_by_right[right_pos].first <= rectangles[left_pos][0])
					mark_right = true;
			}
			if (mark_right)
			{
				vertical = sorted_by_right[right_pos].first;
				while (right_pos < rlen && sorted_by_right[right_pos].first == vertical)
				{
					int index = sorted_by_right[right_pos].second;
					m.erase(rectangles[index][1]);
					right_pos++;
				}						
			}
			if (mark_left)
			{
				vertical = rectangles[left_pos][0];
				while (left_pos < rlen && rectangles[left_pos][0] == vertical)
				{
					int down = rectangles[left_pos][1];
					if (m.count(down)) return false;
					ele temp(rectangles[left_pos][1], rectangles[left_pos][2], rectangles[left_pos][3]);
					m.insert(pair<int, ele>(down, temp));
					auto it = m.find(down);
					it++;
					if (it != m.end())
						if (it->second.bottom < temp.top) return false;
					it = m.find(down);
					if (it != m.begin())
					{
						it--;
						if (it->second.top > temp.bottom) return false;
					}
					left_pos++;
				}
			}
			//if (round == 1)
			//{
			//	smallest = m.begin()->second.bottom;
			//	largest = m.rbegin()->second.top;
			//}
			//if (finished)
			//	return false;
			//if (m.empty())
			//	finished = true;
			// cout << "===================" << endl;
			// for (auto mit : m)
			// 	cout << mit.second.bottom << '\t' << mit.second.top << '\t' << mit.second.right << endl;
			//if (!check(m)) return false;
		}

		int left_most, right_most, top_most, bottom_most;
		bottom_most = left_most = INT_MAX;
		top_most = right_most = INT_MIN;
		int total_area = 0;
		for (auto rit : rectangles)
		{
			total_area += (rit[2] - rit[0])*(rit[3] - rit[1]);
			left_most = min(left_most, rit[0]);
			bottom_most = min(bottom_most, rit[1]);
			right_most = max(right_most, rit[2]);
			top_most = max(top_most, rit[3]);
		}
		return (total_area == (top_most - bottom_most) * (right_most - left_most));
	}

private:
	bool check(map<int, ele> & m)
	{
		if (m.empty()) return true;
		if (m.begin()->second.bottom != smallest) return false;
		if (m.rbegin()->second.top != largest) return false;
		auto it = m.begin();
		ele last = it->second;
		it++;
		for (;it != m.end(); it++)
		{
			if (it->second.bottom != last.top) return false;
			last = it->second;
		}
		return true;
	}

	int smallest, largest;

	struct
	{
		bool operator()(const vector<int> & a, const vector<int> & b)
		{
			return a.front() < b.front();
		}
	} my_comp_func;

	struct
	{
		bool operator()(const pair<int, int> & a, const pair<int, int> & b)
		{
			return a.first < b.first;
		}
	} my_comp_func_2;
};

int main()
{
	
	//1
	// int myInt[5][4] = { { 1,1,3,3 } ,{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4} };
	// vector<vector<int>> v;
	// for (int i = 0; i < 5; i++)
	// {
	// 	vector<int> temp(myInt[i], myInt[i] + 4);
	// 	v.push_back(temp);
	// }

	//2
	int myInt[4][4] = { { 1,1,2,3 } ,{ 1,3,2,4 },{ 3,1,4,2 },{ 3,2,4,4 } };
	vector<vector<int>> v;
	for (int i = 0; i < 4; i++)
	{
		vector<int> temp(myInt[i], myInt[i] + 4);
		v.push_back(temp);
	}

	//3
	// int myInt[4][4] = { { 1,1,3,3 } ,{ 3,1,4,2 },{ 1,3,2,4 },{ 3,2,4,4 } };
	// vector<vector<int>> v;
	// for (int i = 0; i < 4; i++)
	// {
	// 	vector<int> temp(myInt[i], myInt[i] + 4);
	// 	v.push_back(temp);
	// }

	//4
	// int myInt[4][4] = { { 1,1,3,3 } ,{ 3,1,4,2 },{ 1,3,2,4 },{ 2,2,4,4 }};
	// vector<vector<int>> v;
	// for (int i = 0; i < 5; i++)
	// {
	// 	vector<int> temp(myInt[i], myInt[i] + 4);
	// 	v.push_back(temp);
	// }

	Solution s;
	cout << s.isRectangleCover(v) << endl;
    cin.get();
}
