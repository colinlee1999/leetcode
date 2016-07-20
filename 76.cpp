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
		int cover = 0;
		for (auto it : count_target_index)
			cover += it;
		string result;
		int min_len = INT_MAX;
		bool contains = false;
		while (right < s.length())
		{
			count_array[s[right]]++;
			if (!contains)
			{
				if (count_array[s[right]] == count_target[s[right]]) cover -= s[right];
				contains = (cover == 0);
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
};

int main()
{
	Solution s;
	cin.get();
}
