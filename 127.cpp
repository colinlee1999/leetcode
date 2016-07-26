#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <unordered_map>
#include <unordered_set>
#include <string>
#define INT_MIN (1<<31)
#define INT_MAX ~(INT_MIN)
using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
		int wlen = wordList.size();
		unordered_map<string, int> m;
		vector<string> v;
		vector<vector<int>> next(wlen, vector<int>());
		vector<bool> b(wlen, false);
		int count = 0;
		for (auto it : wordList)
		{
			v.push_back(it);
			m[it] = count++;
		}			
		if (m.find(beginWord) == m.end())
		{
			m[beginWord] = count++;
			v.push_back(beginWord);
			wlen++;
		}
		for (int i = 0; i < wlen; i++)
			for (int j = i + 1; j < wlen; j++)
				if (dist(v[i], v[j]) == 1)
				{
					next[i].push_back(j);
					next[j].push_back(i);
				}
		int shortest_length = INT_MAX;
		dfs(0, 
			beginWord, 
			endWord,
			v,
			next,
			b,
			m,
			shortest_length);
		return shortest_length == INT_MAX ? 0 : (shortest_length + 1);
	}

private:
	void dfs(int depth,
		string beginWord,
		string endWord,
		vector<string> & v,
		vector<vector<int>> & next,
		vector<bool> & b,
		unordered_map<string, int> & m,
		int & shortest_length)
	{
		if (beginWord == endWord)
			shortest_length = min(shortest_length, depth);
		else if (dist(beginWord, endWord) == 1)
			shortest_length = min(shortest_length, depth + 1);
		else
		{
			int cur_index = m[beginWord];
			for (int i = 0; i < next[cur_index].size(); i++)
				if (!b[next[cur_index][i]])
				{
					int next_index = next[cur_index][i];
					b[next_index] = true;
					dfs(depth + 1, v[next_index], endWord,
						v, next, b, m, shortest_length);
					b[next_index] = false;
				}
		}
	}

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
	// v.insert("cog");
	v.insert("dog");
	// v.insert("tot");
	// v.insert("hog");
	// v.insert("hop");
	// v.insert("pot");
	// v.insert("dot");
	cout<<s.ladderLength("hot", "dog", v);
    cin.get();
}
