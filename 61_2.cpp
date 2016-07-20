#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> factorial;
		factorial.push_back(1);
		for (int i = 1; i <= n; i++)
			factorial.push_back(factorial.back()*i);
		vector<bool> used(n + 1, false);
		string result = "";
		int pos = n;
		while (pos>0)
		{
			int try_fill = 0;
			while (used[++try_fill]);
			int count = 0;
			int target = (k - 1) / factorial[pos - 1];
			while (count++ < target)
				while (used[++try_fill]);
			k -= target * factorial[pos - 1];
			result += '0' + try_fill;
			used[try_fill] = true;
			pos--;
		}
		return result;
	}
};

int main()
{
    Solution s;
	cout << s.getPermutation(3, 4) << endl;
    cin.get();
}
