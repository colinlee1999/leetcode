#include "iostream"
#include "vector"
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <hash_map>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
		int longest = 0;
		int start_pos = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(')
				st.push(i);
			else
			{
				if (!st.empty())
				{
					int temp = i - st.top() + 1;
					if (temp > longest) longest = temp;
					st.pop();
					if (st.empty())
					{
						if (i - start_pos + 1 > longest) longest = i - start_pos + 1;
					}
					else
					{
						if (i - st.top() > longest) longest = i - st.top();
					}
				}
				else
					start_pos = i + 1;
			}
		}
		return longest;
    }

private:
	stack<int> st;
};

int main()
{
	Solution s;
    cin.get();
}
