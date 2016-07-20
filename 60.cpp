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
			if (k == factorial[pos])
			{
				int try_fill = n + 1;
				while (pos>0)
				{
					while (used[--try_fill]);
					result += '0' + try_fill;
					pos--;
				}
				break;
			}
			int try_fill = 0;
			while (used[++try_fill]);
			while (k > factorial[pos-1])
			{
				k -= factorial[pos-1];
				while (used[++try_fill]);
			}
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
