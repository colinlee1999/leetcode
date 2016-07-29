#include "iostream"
#include "vector"
#include "set"
#include <sstream>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		string ts = s;
		int tslen = ts.length();
		int left = 0;
		int right = tslen - 1;
		while (left <= right && ts[left] == ' ') left++;
		while (left <= right && ts[right] == ' ') right--;
		if (left > right)
		{
			s = "";
			return;
		}
		ts = ts.substr(left, right - left + 1);
		tslen = ts.length();
		left = 0;
		right = tslen - 1;
		char ch;
		while (left < right)
		{
			ch = ts[left];
			ts[left] = ts[right];
			ts[right] = ch;
			left++;
			right--;
		}
		s = "";
		int last_pos = 0, cur_pos = 0;
		while (cur_pos < tslen)
		{
			while (cur_pos < tslen && ts[cur_pos] != ' ')
				cur_pos++;
			left = last_pos;
			right = cur_pos - 1;
			while (right >= left) s += ts[right--];
			s += ' ';
			while (cur_pos < tslen && ts[cur_pos] == ' ') cur_pos++;
			last_pos = cur_pos;
		}
		s.pop_back();
	}
};

int main()
{
	Solution s;
	string str = " ";
	s.reverseWords(str);
	cout<<str<<endl;
    cin.get();
}
