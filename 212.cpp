#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#define INT_MIN 1<<31
#define INT_MAX ~(INT_MIN)
using namespace std;

#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define ALPHABET_SIZE (26)

class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() {
		val = "";
		is_leaf = false;
		has_children = false;
		added = false;
		children_added = false;
		for (int i = 0; i < ALPHABET_SIZE; i++)
			children[i] = NULL;
	}
	TrieNode * children[ALPHABET_SIZE];
	bool is_leaf;
	string val;
	bool has_children;
	bool added;
	bool children_added;
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		TrieNode * p = root;
		for (auto it : word)
		{
			int index = CHAR_TO_INDEX(it);
			if (!p->children[index])
				p->children[index] = new TrieNode();
			p->has_children = true;
			p = p->children[index];
		}
		p->val = word;
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

	TrieNode* root;
};

class Solution {
public:
	Solution()
	{
		pair<int, int> d1(1, 0);
		pair<int, int> d2(-1, 0);
		pair<int, int> d3(0, 1);
		pair<int, int> d4(0, -1);
		direction.push_back(d1);
		direction.push_back(d2);
		direction.push_back(d3);
		direction.push_back(d4);
	}

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> result;
		if (words.empty()) return result;
		if (board.empty()) return result;
		if (board[0].empty()) return result;
		
		int m = board.size();
		int n = board[0].size();

		Trie trie;
		bool found_length_zero = false;
		for (auto it : words)
		{
			if (it != "")
				trie.insert(it);
			else
				found_length_zero = true;
		}
		if (found_length_zero) result.push_back("");

		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				if (trie.root->children[CHAR_TO_INDEX(board[i][j])])
				{
					//cout << "=====================" << endl;
					char backup = board[i][j];
					board[i][j] = 0;
					dfs(i, j, m, n, board, trie.root->children[CHAR_TO_INDEX(backup)], result);
					board[i][j] = backup;
				}

		return result;
	}

private:
	void dfs(int row, int col,
		const int & m, const int & n,
		vector<vector<char>> & board,
		TrieNode * root,
		vector<string> & result)
	{
		//cout << row << ' ' << col << endl;
		if (root->is_leaf && !root->added)
		{
			//cout << "yes" << endl;
			result.push_back(root->val);
			root->added = true;
		}
		if (root->has_children && !root->children_added)
		{
			for (auto dir : direction)
			{
				int new_row = row + dir.first;
				int new_col = col + dir.second;

				if (is_in(new_row, new_col, m, n) && board[new_row][new_col] != 0 && root->children[CHAR_TO_INDEX(board[new_row][new_col])])
				{
					char backup = board[new_row][new_col];
					board[new_row][new_col] = 0;
					dfs(new_row, new_col,
						m, n,
						board,
						root->children[CHAR_TO_INDEX(backup)],
						result);
					board[new_row][new_col] = backup;
				}
			}
			bool all_added = true;
			for (int i = 0; i < ALPHABET_SIZE; i++)
				if (root->children[i])
				{
					if (!root->children[i]->children_added)
						all_added = false;
					if (root->children[i]->is_leaf && !root->children[i]->added)
						all_added = false;
					if (!all_added) break;
				}
			if (all_added)
				root->children_added = true;
		}
	}

	bool is_in(const int & row, const int & col, const int & m, const int & n)
	{
		return row >= 0 && row < m && col >= 0 && col < n;
	}

	vector<pair<int, int>> direction;
};

int main()
{
	Solution s;
	cin.get();
}
