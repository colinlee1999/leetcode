#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
	int numSquares(int n) {
		int least = n;
		int max_try = (int)sqrt(n);
		return find(n, 0, max_try, least);;
	}

private:
	int find(int n, int used, int cur_try, int & least)
	{
		if (cur_try == 1) return n;
		int num_most_fill = n / cur_try / cur_try;
		int temp_least = num_most_fill + used;
		if (num_most_fill* cur_try*cur_try < n) temp_least++;
		if (temp_least >= least) return -1;
		if (num_most_fill*cur_try*cur_try < n)
		{
			for (int num_try_fill = num_most_fill; num_try_fill >= 0; num_try_fill--)
			{
				int gap = n - num_try_fill*cur_try*cur_try;
				int try_find = find(gap, used + num_try_fill, cur_try - 1, least);
				if (try_find != -1)
					least = min(least, try_find + used + num_try_fill);
			}
			return least;
		}
		else
			return num_most_fill;
	}
};

int main()
{
    Solution s;
    cin.get();
}
