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
		bfs(0, 
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
	void bfs(int depth,
		string beginWord,
		string endWord,
		vector<string> & v,
		vector<vector<int>> & next,
		vector<bool> & b,
		unordered_map<string, int> & m,
		int & shortest_length)
	{
		queue<pair<string, int>> q;
		q.push(pair<string, int>(beginWord, 0));
		b[m[beginWord]] = true;
		while (!q.empty())
		{
			pair<string, int> tfront = q.front();
			int temp = dist(tfront.first, endWord);
			if (temp <= 1)
			{
				shortest_length = tfront.second + temp;
				return;
			}
			q.pop();
			int cur_index = m[tfront.first];
			for (int i = 0; i < next[cur_index].size(); i++)
			{
				int next_index = next[cur_index][i];
				if (!b[next_index])
				{
					b[next_index] = true;
					q.push(pair<string, int>(v[next_index], tfront.second + 1));
				}
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
