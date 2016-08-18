#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
#include <stack>
#include <deque>
using namespace std;

class Solution {
public:
	Solution()
	{
		priority.insert(pair<char, int>('+', 0));
		priority.insert(pair<char, int>('-', 0));
		priority.insert(pair<char, int>('*', 1));
		priority.insert(pair<char, int>('/', 1));
	}

	int calculate(string s) {
		s = s + "+";
		int slen = s.length();
		int pos = 0;
		while (pos < slen && s[pos] == ' ') pos++;
		if (s[pos] == '-' || s[pos] == '+')
			operands.push(0);
		while (pos < slen)
		{
			switch (s[pos])
			{
			case '+':
			case '-':
			case '*':
			case '/':
				while (!ops.empty() && priority[s[pos]] <= ops.top().second)
					calc();
				ops.push(pair<char, int>(s[pos], priority[s[pos]]));
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
			{
				int temp = 0;
				while (pos < slen && s[pos] >= '0' && s[pos] <= '9')
				{
					temp = temp * 10 + s[pos] - '0';
					pos++;
				}
				pos--;
				operands.push(temp);
			}
				break;
			default:
				break;
			}
			pos++;
		}
		return operands.top();
	}

private:
	void calc()
	{
		int a = operands.top();
		operands.pop();
		int b = operands.top();
		operands.pop();
		char op = ops.top().first;
		ops.pop();
		switch (op)
		{
		case '+':
			operands.push(b + a);
			break;
		case '-':
			operands.push(b - a);
			break;
		case '*':
			operands.push(b * a);
			break;
		case '/':
			operands.push(b / a);
			break;
		default:
			break;
		}
	}

	unordered_map<char, int> priority;
	stack<int> operands;
	stack<pair<char, int>> ops;
};

int main()
{
    Solution s;
    cin.get();
}
