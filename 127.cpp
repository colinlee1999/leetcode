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
			shortest_length = temp;
		else
		{
			queue<pair<string, int>> q;
			q.push(pair<string, int>(beginWord, 0));
			wordList.erase(beginWord);
			while (!q.empty())
			{
				pair<string, int> tfront = q.front();
				q.pop();
				unordered_set<string> to_be_removed;
				bool found = false;
				for (auto it : wordList)
					if (dist(tfront.first, it) == 1)
					{
						q.push(pair<string, int>(it, tfront.second + 1));
						int temp = dist(it, endWord);
						if (temp <= 1)
						{
							shortest_length = tfront.second + 1 + temp;
							found = true;
							break;
						}
						to_be_removed.insert(it);
					}
				if (found) break;
				for (auto it : to_be_removed)
					wordList.erase(it);
			}
		}
		return shortest_length == INT_MAX ? 0 : (shortest_length + 1);
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
	v.insert("cog");
	v.insert("dog");
	v.insert("tot");
	v.insert("hog");
	v.insert("hop");
	v.insert("pot");
	v.insert("dot");
	cout<<s.ladderLength("hot", "dog", v);
    cin.get();
}
