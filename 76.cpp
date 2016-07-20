#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <sstream>
#include <unordered_set>
#define INT_MIN 1<<31
#define INT_MAX ~(INT_MIN)
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		int slen = s.length();
		int tlen = t.length();
		int left = 0;
		int right = 0;
		vector<int> count_array(256, 0);
		vector<int> count_target(256, 0);
		unordered_set<int> count_target_index;
		for (auto it : t)
		{
			count_target[it]++;
			count_target_index.insert(it);
		}
		string result;
		int min_len = INT_MAX;
		bool contains = false;
		while (right < s.length())
		{
			if (contains)
				count_array[s[right]]++;
			else
			{
				count_array[s[right]]++;
				contains = count_array_contains(count_array, count_target, count_target_index);
			}
			right++;
			if (contains)
			{
				while (count_array[s[left]]>count_target[s[left]])
				{
					count_array[s[left]]--;
					left++;
				}
				if (right - left < min_len)
				{
					min_len = right - left;
					result = s.substr(left, min_len);
				}
			}
		}
		return result;
	}

private:
	bool count_array_contains(vector<int> & count_array,
		vector<int> & count_target,
		unordered_set<int> count_target_index)
	{
		for (auto it : count_target_index)
			if (count_array[it] < count_target[it])
				return false;
		return true;
	}
};

int main()
{
	Solution s;
	cin.get();
}
