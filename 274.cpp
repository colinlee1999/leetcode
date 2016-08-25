#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
#include <stack>
#include <deque>
using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		vector<int> bucket((int)citations.size() + 1, 0);
		int blen = (int)citations.size();
		for (auto it : citations)
		{
			if (it > blen) bucket[blen]++;
			else bucket[it]++;
		}
		int k = 0;
		int result = 0;
		for (int it = blen; it >= 0; it--)
		{
			while (bucket[it] > 0)
			{
				k++;
				bucket[it]--;
				if (k <= it)
					result = k;
				else break;
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
