#include "iostream"
#include "vector"
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> result;
		int wlen = words.size();
		int slen = s.length();
		if (wlen == 0) return result;
		int word_len = words[0].length();
		if (slen == 0 || slen < word_len) return result;

		unordered_map<string, int> m_target;
		for (auto w : words)
		{
			auto it = m_target.find(w);
			if (it == m_target.end()) m_target[w] = 1;
			else it->second++;
		}

		for (int i = 0; i < word_len; i++)
		{
			int contains = 0;
			unordered_map<string, int> m_cur;
			int left = i;
			int right = i;
			while (right + word_len <= slen)
			{
				string right_word = s.substr(right, word_len);
				auto it = m_target.find(right_word);
				if (it != m_target.end())
				{
					auto m_cur_it = m_cur.find(right_word);
					if (m_cur_it != m_cur.end()) m_cur_it->second++;
					else m_cur[right_word] = 1;
					contains++;
					while (left + word_len <= right && m_cur[right_word] > m_target[right_word])
					{
						string left_word = s.substr(left, word_len);
						m_cur[left_word]--;
						contains--;
						left += word_len;
					}
					if (contains == wlen)
						result.push_back(left);
				}
				else
				{
					contains = 0;
					m_cur.clear();
					left = right + word_len;
				}
				right += word_len;
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
