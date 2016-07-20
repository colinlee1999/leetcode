#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		int pTable[10] = { 1 };
		for (int i = 1; i <= 9; i++) {
			pTable[i] = i * pTable[i - 1];
		}
		string result;
		vector<char> numSet;
		numSet.push_back('1');
		numSet.push_back('2');
		numSet.push_back('3');
		numSet.push_back('4');
		numSet.push_back('5');
		numSet.push_back('6');
		numSet.push_back('7');
		numSet.push_back('8');
		numSet.push_back('9');
		while (n > 0) {
			int temp = (k - 1) / pTable[n - 1];
			result += numSet[temp];
			numSet.erase(numSet.begin() + temp);
			k = k - temp * pTable[n - 1];
			n--;
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
