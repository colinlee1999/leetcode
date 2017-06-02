#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int findIntegers(int num) {
		vector<int> v = getBinary(num);
		vector<int> f(v.size(), 0);  // 0
		vector<int> g(v.size(), 0);  // 1
		f[0] = 1;
		g[0] = 1;
		for (int i = 1; i < v.size(); i++) {
			f[i] = f[i - 1] + g[i - 1];
			g[i] = f[i - 1];
		}
		return findHelper(v, f, g, v.size() - 1);
	}

private:
	int findHelper(vector<int> & v, vector<int> & f, vector<int> & g, int pos) {
		if (pos == 0) {
			return 2;
		}
		else {
			int result = f[pos - 1] + g[pos - 1];
			int npos = pos - 1;
			while (npos >= 0 && v[npos] != 1) {
				npos--;
			}
			if (npos < 0) {
				result += 1;  // 10...00
				return result;
			}
			else if (npos + 1 == pos) {
				if (npos == 0) {
					result += 1;  // 10
					return result;
				}
				else {
					result += f[pos - 2] + g[pos - 2];  // 10x...xx
					return result;
				}
			}
			else {
				return result + findHelper(v, f, g, npos);  // 10+1x*
			}
		}
	}

	vector<int> getBinary(int num) {
		vector<int> v;
		while (num > 0) {
			v.push_back(num & 1);
			num /= 2;
		}
		return v;
	}
};

int main()
{
	Solution s;
	int n;
	cin >> n;
	cout << s.findIntegers(n);
	cin.get();
}
