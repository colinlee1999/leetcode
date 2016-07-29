#include "iostream"
#include "vector"
#include "set"
#include <sstream>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> s;
		for (auto it : tokens)
		{
			int a;
			if (it == "+")
			{
				a = s.top();
				s.pop();
				s.top() += a;
			}
			else if (it == "-")
			{
				a = s.top();
				s.pop();
				s.top() -= a;
			}
			else if (it == "*")
			{
				a = s.top();
				s.pop();
				s.top() *= a;
			}
			else if (it == "/")
			{
				a = s.top();
				s.pop();
				s.top() /= a;
			}
			else
			{

				istringstream is(it);
				int a;
				is >> a;
				s.push(a);
			}
		}
		return(s.top());
	}
};

int main()
{
	Solution s;
    cin.get();
}
