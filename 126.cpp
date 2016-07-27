#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>
#include <algorithm>
#define INT_MIN (1<<31)
#define INT_MAX (~(INT_MIN))
using namespace std;

class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string>& wordList) {
		vector<vector<string>> result;
		if (beginWord == endWord) 
		{
			result.push_back(vector<string>(1, beginWord));
			return result;
		}
		vector<cell> qfront, qback, *q;
		int qfront_start, qback_start, *qstart;
		unordered_multimap<string, int> front_reach, back_reach, *cur_reach, *another_reach;
		unordered_set<string> front_wordList(wordList), back_wordList(wordList), *wl;
		int cur_step, another_step;

		qfront.push_back(cell(beginWord, 0, -1));
		qfront_start = 0;
		front_wordList.erase(beginWord);
		front_reach.insert(pair<string, int>(beginWord, 0));

		qback.push_back(cell(endWord, 0, -1));
		qback_start = 0;
		back_wordList.erase(endWord);
		back_reach.insert(pair<string, int>(endWord, 0));

		bool found = false;
		while (qfront_start<qfront.size() || qback_start<qback.size())
		{
			if (found) break;
			bool feasible = false;
			if (((int)qfront.size() - qfront_start <= (int)qback.size() - qback_start || ((int)qfront.size() - qfront_start > (int)qback.size() - qback_start && back_wordList.size() == 0)) && front_wordList.size() > 0 && qfront.size() > qfront_start)
			{
				q = &qfront;
				qstart = &qfront_start;
				cur_reach = &front_reach;
				another_reach = &back_reach;
				cur_step = qfront[qfront_start].step;
				another_step = qback[qback_start].step;
				wl = &front_wordList;
				feasible = true;
			}
			if (((int)qfront.size() - qfront_start > (int)qback.size() - qback_start || ((int)qfront.size() - qfront_start <= (int)qback.size() - qback_start && front_wordList.size() == 0)) && back_wordList.size() > 0 && qback.size() > qback_start)
			{
				q = &qback;
				qstart = &qback_start;
				cur_reach = &back_reach;
				another_reach = &front_reach;
				cur_step = qback[qback_start].step;
				another_step = qfront[qfront_start].step;
				wl = &back_wordList;
				feasible = true;
			}
			if (!feasible) break;
			cur_reach->clear();
			unordered_set<string> to_be_removed;
			while (*qstart < q->size())
			{
				cell tfront = q->at(*qstart);
				if (tfront.step != cur_step) break;
				string cur_str(tfront.str);
				for (auto &ch : cur_str)
				{
					auto c0 = ch;
					for (ch = 'a'; ch <= 'z'; ch++)
						if (ch != c0 && wl->count(cur_str))
						{
							if (another_reach->count(cur_str))
								found = true;								
							to_be_removed.insert(cur_str);
							cur_reach->insert(pair<string, int>(cur_str, q->size()));
							q->push_back(cell(cur_str, cur_step + 1, *qstart));
						}
					ch = c0;
				}
				(*qstart)++;
			}
			for (auto it : to_be_removed) wl->erase(it);
		}
		if (found)
		{
			for (auto it1 = front_reach.begin(); it1 != front_reach.end(); it1++)
				for (auto it2 = back_reach.begin(); it2 != back_reach.end(); it2++)
					if (it1->first == it2->first)
					{
						vector<string> tv;
						int front_pos = it1->second;
						int back_pos = it2->second;
						tv.push_back(it1->first);
						while (qfront[front_pos].from != -1)
						{
							front_pos = qfront[front_pos].from;
							tv.push_back(qfront[front_pos].str);
						}
						reverse(tv.begin(), tv.end());
						while (qback[back_pos].from != -1)
						{
							back_pos = qback[back_pos].from;
							tv.push_back(qback[back_pos].str);
						}
						result.push_back(tv);
					}
		}
		for (int i = 0; i < result.size(); i++)
		{
			for (int j = 0; j < result[i].size(); j++)
				cout << result[i][j] << ' ';
			cout << endl;
		}
		return result;
	}

private:
	struct cell
	{
		cell(string str, int step, int from)
		{
			this->str = str;
			this->step = step;
			this->from = from;
		}
		string str;
		int step, from;
	};
};

int main()
{
    Solution s;
	unordered_set<string> v;
	// v.insert("hot");
	// v.insert("dog");
	// v.insert("cog");
	// v.insert("tot");
	// v.insert("hog");
	// v.insert("hop");
	// v.insert("pot");
	// v.insert("dot");
	// v.insert("lot");
	// v.insert("log");
	// s.findLadders("hit", "cog", v);
	v.insert("ted");
	v.insert("tex");
	v.insert("red");
	v.insert("tax");
	v.insert("tad");
	v.insert("den");
	v.insert("rex");
	v.insert("pee");
	s.findLadders("red", "tax", v);
    cin.get();
}
