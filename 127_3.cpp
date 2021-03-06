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
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList)
	{
		if (beginWord == endWord) return 2;
		int depth = 1;
		unordered_set<string> forward, backward;
		forward.insert(beginWord);
		backward.insert(endWord);
		while (!forward.empty())
		{
			unordered_set<string> nextLevel;
			for (auto& w : forward) wordList.erase(w);
			for (auto& w : backward) wordList.erase(w);
			for (auto& word : forward)
			{
				string cur(word);
				for (auto& c : cur)
				{
					char c0 = c;
					for (c = 'a'; c <= 'z'; ++c)
					{
						if (c != c0)
						{
							if (backward.count(cur)) return depth + 1;
							if (wordList.count(cur)) nextLevel.insert(cur);
						}
					}
					c = c0;
				}
			}
			depth++;
			forward.swap(nextLevel);
			if (forward.size() > backward.size()) backward.swap(forward);
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
	//v.insert("cog");
	//v.insert("tot");
	//v.insert("hog");
	//v.insert("hop");
	//v.insert("pot");
	//v.insert("dot");
	cout<<s.ladderLength("hot", "dog", v);
    cin.get();
}
