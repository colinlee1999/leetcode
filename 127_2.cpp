#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>
#define INT_MIN (1<<31)
#define INT_MAX (~(INT_MIN))
using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
		int shortest_length = INT_MAX;
		if (beginWord == endWord) return 1;
		queue<pair<string, int>> qfront, qback, *q;
		unordered_set<string> front_reach, back_reach, *cur_reach, *another_reach;
		unordered_set<string> front_wordList(wordList), back_wordList(wordList), *wl;
		int cur_step, another_step;

		qfront.push(pair<string, int>(beginWord, 1));
		front_wordList.erase(beginWord);
		front_reach.insert(beginWord);

		qback.push(pair<string, int>(endWord, 1));
		back_wordList.erase(endWord);
		back_reach.insert(endWord);

		while (!qfront.empty() || !qback.empty())
		{
			bool feasible = false;
			if ((qfront.size() <= qback.size() || (qfront.size() > qback.size() && back_wordList.size() == 0)) && front_wordList.size() > 0 && !qfront.empty())
			{
				q = &qfront;
				cur_reach = &front_reach;
				another_reach = &back_reach;
				cur_step = qfront.front().second;
				another_step = qback.front().second;
				wl = &front_wordList;
				feasible = true;
			}
			if ((qfront.size() > qback.size() || (qfront.size() <= qback.size() && front_wordList.size() == 0)) && back_wordList.size() > 0 && !qback.empty())
			{
				q = &qback;
				cur_reach = &back_reach;
				another_reach = &front_reach;
				cur_step = qback.front().second;
				another_step = qfront.front().second;
				wl = &back_wordList;
				feasible = true;
			}
			if (!feasible) break;
			(*cur_reach).clear();
			while (!(*q).empty())
			{
				pair<string, int> tfront = (*q).front();
				if (tfront.second != cur_step) break;
				(*q).pop();
				unordered_set<string> to_be_removed;
				string cur_str(tfront.first);
				for (auto &ch : cur_str)
				{
					auto c0 = ch;
					for (ch = 'a'; ch <= 'z'; ch++)
						if (ch != c0 && (*wl).count(cur_str))
						{
							if ((*another_reach).count(cur_str))
								return cur_step + another_step;
							to_be_removed.insert(cur_str);
							(*cur_reach).insert(cur_str);
							(*q).push(pair<string, int>(cur_str, cur_step + 1));
						}
					ch = c0;
				}
				for (auto it : to_be_removed)
					(*wl).erase(it);
			}
		}
		return 0;
	}
};

int main()
{
    Solution s;
	unordered_set<string> v;
	v.insert("hot");
	v.insert("dog");
	v.insert("cog");
	v.insert("tot");
	v.insert("hog");
	v.insert("hop");
	v.insert("pot");
	v.insert("dot");
	cout<<s.ladderLength("hot", "dog", v);
    cin.get();
}
