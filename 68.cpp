#include "iostream"
#include "vector"
#include "set"
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> result;
		int wlen = words.size();
		if (wlen == 0) return result;
		for (int pos = 0; pos < wlen;)
		{
			int temp_length = words[pos].length();
			int end_pos = pos + 1;
			while (end_pos < wlen && temp_length + 1 + (int)words[end_pos].length() <= maxWidth)
				temp_length += 1 + (int)words[end_pos++].length();
			string cur_line;
			if (end_pos == pos + 1)
				cur_line = words[pos++];
			else
			{
				vector<int> space(end_pos - pos - 1, 1);
				if (end_pos < wlen)
				{
					int even = (maxWidth - temp_length) / (end_pos - pos - 1);
					int remainder = maxWidth - temp_length - even * (end_pos - pos - 1);
					for (int i = 0; i < space.size(); i++) space[i] += even;
					for (int i = 0; i < remainder; i++) space[i]++;
				}
				cur_line = words[pos++];
				for (auto it : space)
				{
					while (it-- > 0) cur_line += ' ';
					cur_line += words[pos++];
				}
			}
			while (cur_line.length() < maxWidth) cur_line += ' ';
			result.push_back(cur_line);
		}
		return result;
	}
};

int main()
{
	Solution s;
    cin.get();
}
