#include "iostream"
#include "vector"
#include "set"
#include <sstream>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	int maxPoints(vector<Point>& points) {
		map<pair<int, int>, int> m;
		vector<Point> v;
		vector<int> count;
		for (auto it : points)
		{
			pair<int, int> cur_point(it.x, it.y);
			if (m.count(cur_point))
				count[m[cur_point]]++;
			else
			{
				m[cur_point] = count.size();
				count.push_back(1);				
				v.push_back(it);
			}
		}
		if (v.size() == 1) return count[0];
		int result = 0;
		for (int i = 0; i < v.size(); i++)
			for (int j = i + 1; j < v.size(); j++)
			{
				int temp_result = count[i] + count[j];
				Point cur_dir_vec(v[j].x - v[i].x, v[j].y - v[i].y);
				for (int k = 0; k < v.size(); k++)
					if (k != i && k != j)
					{
						Point new_dir_vec(v[k].x - v[i].x, v[k].y - v[i].y);
						if ((long long)cur_dir_vec.x * (long long)new_dir_vec.y == (long long)cur_dir_vec.y * (long long)new_dir_vec.x)
							temp_result += count[k];
					}
				result = max(result, temp_result);
			}
		return result;
	}
};

int main()
{
	Solution s;
    cin.get();
}
