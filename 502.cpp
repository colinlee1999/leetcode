#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
	int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
		int len = Profits.size();
		quickSort(Capital, Profits, 0, len - 1);
		priority_queue<int> pq;
		int pos = 0;
		while (k--) {
			while (pos < len && Capital[pos] <= W) {
				pq.push(Profits[pos]);
				pos++;
			}
			if (pq.empty()) {
				break;
			}
			W += pq.top();
			pq.pop();
		}
		return W;
	}

private:
	void quickSort(vector<int> & Capital, vector<int> & Profits, int left, int right) {
		int i = left, j = right;
		int tmp;
		int pivot = Capital[(left + right) / 2];

		/* partition */
		while (i <= j) {
			while (Capital[i] < pivot)
				i++;
			while (Capital[j] > pivot)
				j--;
			if (i <= j) {
				tmp = Capital[i];
				Capital[i] = Capital[j];
				Capital[j] = tmp;
				tmp = Profits[i];
				Profits[i] = Profits[j];
				Profits[j] = tmp;
				i++;
				j--;
			}
		};

		/* recursion */
		if (left < j)
			quickSort(Capital, Profits, left, j);
		if (i < right)
			quickSort(Capital, Profits, i, right);
	}
};

int main()
{
	Solution s;
	cin.get();
}
