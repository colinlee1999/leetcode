#include "iostream"
#include "vector"
#include <set>
#include <map>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
 
class Solution {
public:
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> result;
		bool found = false;
		int pos = -1;
		for (int i = 0; i < intervals.size(); i++)
			if (intervals[i].end >= newInterval.start)
			{
				pos = i;
				break;
			}
			else
				result.push_back(intervals[i]);
		if (pos == -1)
			result.push_back(newInterval);
		else
		{
			Interval temp;
			temp.start = min(intervals[pos].start, newInterval.start);
			int right_most = newInterval.end;
			for (; pos < intervals.size(); pos++)
			{
				if (intervals[pos].start>right_most) break;
				right_most = max(right_most, intervals[pos].end);
			}
			temp.end = right_most;
			result.push_back(temp);
			for (; pos < intervals.size(); pos++)
				result.push_back(intervals[pos]);
		}
		return result;
	}
};

int main()
{
	Solution s;
    cin.get();
}
