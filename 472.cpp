#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define ALPHABET_SIZE (26)

class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() {
		is_leaf = false;
		for (int i = 0; i < ALPHABET_SIZE; i++)
			children[i] = NULL;
	}
	TrieNode * children[ALPHABET_SIZE];
	bool is_leaf;
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
		root->is_leaf = true;
	}

	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode * p = root;
		for (auto it : word)
		{
			int index = CHAR_TO_INDEX(it);
			if (!p->children[index])
				p->children[index] = new TrieNode();
			p = p->children[index];
		}
		p->is_leaf = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		TrieNode * p = root;
		for (auto it : word)
		{
			int index = CHAR_TO_INDEX(it);
			if (!p->children[index]) return false;
			p = p->children[index];
		}
		return p->is_leaf;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		TrieNode * p = root;
		for (auto it : prefix)
		{
			int index = CHAR_TO_INDEX(it);
			if (!p->children[index]) return false;
			p = p->children[index];
		}
		return true;
	}

	bool dfs(const string & s, int pos, int depth) {
		if (pos == s.length()) {
			if (depth <= 1) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			TrieNode * p = root;
			vector<int> v;
			for (int i = pos; i < s.size(); i++) {
				int index = CHAR_TO_INDEX(s[i]);
				if (!p->children[index]) {
					break;
				}
				p = p->children[index];
				if (p->is_leaf) {
					v.push_back(i + 1);		
				}
			}
			for (auto it = v.rbegin(); it != v.rend(); ++it) {
				//printf("%s\t%d\t%d\n", s.c_str(), *it, depth);
				bool tmp = dfs(s, *it, depth + 1);
				if (!tmp) {
					return false;
				}
			}
			return true;
		}
	}

private:
	TrieNode* root;
};

class Solution {
public:
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		Trie trie;
		for (auto it : words) {
			trie.insert(it);
		}
		vector<string> result;
		for (auto it : words) {
			if (!trie.dfs(it, 0, 0)) {
				result.push_back(it);
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
