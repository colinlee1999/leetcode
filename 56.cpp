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
    vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> result;
		sort(intervals.begin(), intervals.end(), my_comp_func);
		for (int i = 0; i < intervals.size();)
		{
			Interval temp;
			temp.start = intervals[i].start;
			int right_most = intervals[i].end;
			while (i < intervals.size() && intervals[i].start <= right_most)
			{
				right_most = max(right_most, intervals[i].end);
				i++;
			}
			temp.end = right_most;
			result.push_back(temp);
		}
		return result;
    }

private:
	struct
	{
		bool operator()(const Interval & a, const Interval & b)
		{
			return (a.start < b.start);
		}
	} my_comp_func;
};

int main()
{
	Solution s;
    cin.get();
}
