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
		table.push_back(1);
		long long primary = 1;
		for (int i = 1; i < 11; i++)
		{
			table.push_back(primary * 9 * i + primary * 10);
			primary *= 10;
		}
		sum_table.push_back(table.front());
		for (int i = 1; i < 11; i++)
			sum_table.push_back(sum_table.back() + table[i]);
	}

	int countDigitOne(int n) {
		if (n < 1) return 0;
		vector<int> digits;
		vector<int> reverse_n;
		vector<int> power_of_ten;
		long long power = 1;
		int n_backup = n;
		while (n > 0)
		{
			digits.push_back(n % 10);
			power_of_ten.push_back(power);
			power *= 10;
			reverse_n.push_back(n_backup % power);
			n /= 10;
		}
		//for (auto it : power_of_ten)
		//	cout << it << ' ';
		//cout << endl;
		//for (auto it : reverse_n)
		//	cout << it << ' ';
		//cout << endl;
		return count(digits, reverse_n, power_of_ten, n, (int)digits.size() - 1);
	}

private:
	int count(const vector<int> & digits, const vector<int> & reverse_n, const vector<int> & power_of_ten, const int & n, const int pos)
	{
		if (pos == 0) return (digits[pos] >= 1);
		int result = digits[pos] * sum_table[pos - 1];
		if (digits[pos] == 1) result += reverse_n[pos - 1] + 1;
		else if (digits[pos] > 1) result += power_of_ten[pos];
		return result + count(digits, reverse_n, power_of_ten, n, pos - 1);
	}

	vector<long long> sum_table, table;
};

int main()
{
    Solution s;
	cout << s.countDigitOne(199) << endl;
    cin.get();
}
