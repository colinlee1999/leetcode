#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
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

	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

class WordDictionary {
public:

	// Adds a word into the data structure.
	void addWord(string word) {
		trie.insert(word);
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		return trie_search(trie.root, word, 0);
	}

private:
	bool trie_search(const TrieNode * root, const string & word, int pos)
	{
		if (pos == word.length())
		{
			if (root->is_leaf) return true;
		}
		else
		{
			if (word[pos] == '.')
			{
				bool found = false;
				for (int i = 0; i<ALPHABET_SIZE; i++)
					if (root->children[i])
					{
						found = trie_search(root->children[i], word, pos + 1);
						if (found) break;
					}
				return found;
			}
			else
			{
				if (root->children[CHAR_TO_INDEX(word[pos])])
					return trie_search(root->children[CHAR_TO_INDEX(word[pos])], word, pos + 1);
				else return false;
			}
		}
		return false;
	}

	Trie trie;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main()
{
    cin.get();
}
