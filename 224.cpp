#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
	int calculate(string s) {
		if (s.front() == '-' || s.front() == '+') s = "0" + s;
		s = "(" + s + ")";
		int pos = 0;
		int slen = s.length();
		bool num_mode = false;
		int num;
		while (pos < slen)
		{
			// cout<<pos<<":\t"<<s[pos]<<endl;
			switch (s[pos])
			{
			case '(':
				stack_push_bracket(s[pos]);
				break;
			case ')':
			{
				if (num_mode)
				{
					stack_push_num(num);
					num_mode = false;
				}
				int count = 0;
				while (st.size()>1)
				{
					// cout<<"ok"<<endl;
					stack_element st1 = st.top();
					st.pop();
					if (count == 0 && st.top().cate == 2)
					{
						st.pop();
						st.push(st1);
						count++;
						continue;
					}
					st.push(st1);
					if (!check_stack()) break;
				}
				break;
			}
			case '+':
			case '-':
			{
				if (num_mode)
				{
					stack_push_num(num);
					num_mode = false;
				}
				check_stack();
				stack_push_op(s[pos]);
				break;
			}
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
				if (!num_mode)
				{
					num_mode = true;
					num = s[pos] - '0';
				}
				else
					num = num * 10 + s[pos] - '0';
			}
			default:
				break;
			}
			pos++;
		}
		return st.top().c.num;
	}

private:
	int calc(int a, int b, char op)
	{
		if (op == '+')
			return a + b;
		else if (op == '-')
			return a - b;
		return 0;
	}

	bool check_stack()
	{
		if (st.size() >= 3)
		{
			stack_element st1 = st.top();
			st.pop();
			stack_element st2 = st.top();
			st.pop();
			stack_element st3 = st.top();
			st.pop();
			if (st3.cate == 0 && st2.cate == 1 && st1.cate == 0)
			{
				// cout<<"==============="<<endl;
				// cout << st3.c.num <<endl;
				// cout << st2.c.op <<endl;
				// cout << st1.c.num <<endl;
				stack_push_num(calc(st3.c.num, st1.c.num, st2.c.op));
				return true;
			}
			else
			{
				st.push(st3);
				st.push(st2);
				st.push(st1);
			}
		}
		return false;
	}

	void stack_push_num(int num)
	{
		stack_element n;
		n.cate = 0;
		n.c.num = num;
		st.push(n);
	}

	void stack_push_op(char op)
	{
		stack_element n;
		n.cate = 1;
		n.c.op = op;
		st.push(n);
	}

	void stack_push_bracket(char bracket)
	{
		stack_element n;
		n.cate = 2;
		n.c.bracket = bracket;
		st.push(n);
	}

	union content
	{
		int num;
		char bracket;
		char op;
	};

	struct stack_element
	{
		int cate; // 0 means number, 1 means operators, 2 means bracket
		content c;
	};

	stack<stack_element> st;
};

int main()
{
    Solution s;
	cout << s.calculate("2-1+2") << endl;
    cin.get();
}
