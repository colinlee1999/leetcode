#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
#include <unordered_set>
#include <unordered_map>
#define	INT_MIN	1<<31
#define	INT_MAX	~(INT_MIN)
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		int nlen1 = num1.length();
		int nlen2 = num2.length();
		vector<int> temp(nlen1 + nlen2, 0);
		for (int i = 0; i < nlen1; i++)
			for (int j = 0; j < nlen2; j++)
				temp[i + j] += (num1[nlen1 - 1 - i] - '0') * (num2[nlen2 - 1 - j] - '0');
		int carry = 0;
		for (int i = 0; i < temp.size(); i++)
		{
			temp[i] += carry;
			carry = temp[i] / 10;
			temp[i] %= 10;
		}
		string result = "";
		int i = temp.size() - 1;
		while (i > 0 && temp[i] == 0) i--;
		for (; i >= 0; i--)
			result += '0' + temp[i];
		return result;
	}
};

int main()
{
	Solution s;
    cin.get();
}
