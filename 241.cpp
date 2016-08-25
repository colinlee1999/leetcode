#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
#include <stack>
#include <deque>
using namespace std;

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int> operands;
		vector<char> ops;
		int ilen = input.length();
		int pos = 0;
		while (pos < ilen)
		{
			if (input[pos] >= '0' && input[pos] <= '9')
			{
				int temp = 0;
				while (pos < ilen && input[pos] >= '0' && input[pos] <= '9')
				{
					temp = temp * 10 + input[pos] - '0';
					pos++;
				}
				operands.push_back(temp);
				pos--;
			}
			else if (input[pos] == '+' || input[pos] == '-' || input[pos] == '*' || input[pos] == '/')
				ops.push_back(input[pos]);
			pos++;
		}
		if (ops.empty()) return operands;
		else return dfs(operands, ops, 0, (int)ops.size());
	}

private:
	vector<int> dfs(const vector<int> & operands,
		const vector<char> & ops,
		int left, int right)
	{
		if (left == right)
			return vector<int>(1, operands[left]);
		vector<int> left_result, right_result;
		vector<int> result;
		for (int mid = left; mid < right; mid++)
		{
			left_result = dfs(operands, ops, left, mid);
			right_result = dfs(operands, ops, mid + 1, right);
			for (auto lit : left_result)
				for (auto rit : right_result)
				{
					int temp;
					switch (ops[mid])
					{
					case '+':
						temp = lit + rit;
						break;
					case '-':
						temp = lit - rit;
						break;
					case '*':
						temp = lit * rit;
						break;
					case '/':
						temp = lit / rit;
						break;
					default:
						break;
					}
					result.push_back(temp);
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
