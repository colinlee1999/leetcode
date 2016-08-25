#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
	int hIndex(vector<int>& citations) {
		if (citations.empty() || citations.back() == 0) return 0;
		if (citations.front() >= citations.size()) return citations.size();
		int clen = citations.size();
		int left = 0;
		int right = clen - 1;
		int mid;
		while (left + 1 < right)
		{
			mid = left + (right - left) / 2;
			if (citations[mid] >= clen - mid) right = mid;
			else left = mid;
		}
		return clen - right;
	}
};

int main()
{
    Solution s;
    cin.get();
}
