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
		int temp = dist(beginWord, endWord);
		if (temp <= 1)
			shortest_length = 1 + temp;
		else
		{
			queue<pair<string, int>> qfront, qback, *q;
			unordered_set<string> front_reach, back_reach, *cur_reach, *another_reach;
			unordered_set<string> front_wordList(wordList), back_wordList(wordList);
			int cur_step, another_step;
			bool found = false;

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
					wordList = front_wordList;
					feasible = true;
				}
				if ((qfront.size() > qback.size() || (qfront.size() <= qback.size() && front_wordList.size() == 0)) && back_wordList.size() > 0 && !qback.empty())
				{
					q = &qback;
					cur_reach = &back_reach;
					another_reach = &front_reach;
					cur_step = qback.front().second;
					another_step = qfront.front().second;
					wordList = back_wordList;
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
					for (int i = 0; i < tfront.first.length(); i++)
					{
						string temps = tfront.first;
						for (char ch = 'a'; ch <= 'z'; ch++)
						{
							temps[i] = ch;
							if (wordList.find(temps) != wordList.end())
							{
								if ((*another_reach).find(temps) != (*another_reach).end())
								{
									shortest_length = cur_step + another_step;
									found = true;
									break;
								}
								to_be_removed.insert(temps);
								(*cur_reach).insert(temps);
								(*q).push(pair<string, int>(temps, cur_step + 1));
							}
						}
						if (found) break;
					}
					if (found) break;
					for (auto it : to_be_removed)
						wordList.erase(it);
				}
				if (found) break;
			}
		}
		return shortest_length == INT_MAX ? 0 : shortest_length;
	}

private:
	int dist(string word1, string word2)
	{
		int d = 0;
		for (int i = 0; i < word1.size(); i++)
			if (word1[i] != word2[i]) d++;
		return d;
	}
};

int main()
{
    Solution s;
	unordered_set<string> v;
	v.insert("hot");
	v.insert("dog");
	//v.insert("cog");
	//v.insert("tot");
	//v.insert("hog");
	//v.insert("hop");
	//v.insert("pot");
	//v.insert("dot");
	cout<<s.ladderLength("hot", "dog", v);
    cin.get();
}
