#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_map>
#include <ctime>
#include <algorithm>
using namespace std;

class Solution {
public:
	Solution()
	{
		next.push_back(4);
		next.push_back(2);
		next.push_back(4);
		next.push_back(2);
		next.push_back(4);
		next.push_back(6);
		next.push_back(2);
		next.push_back(6);
	}

	int countPrimes(int n) {
		if (n <= 2) return 0;
		if (n <= 3) return 1;
		if (n <= 5) return 2;
		if (n <= 7) return 3;
		vector<bool> isprime(n, true);
		int upper = (int)sqrt(n);
		int count = 3;
		//vector<int> result;
		int n_pos = 0;
		for (int i = 7; i < n;)
		{
			if (isprime[i])
			{
				//result.push_back(i);
				count++;
				if (i <= upper)
				{
					int cur_pos = n_pos;
					for (int j = i*i; j < n;)
					{
						isprime[j] = false;
						j += next[cur_pos] * i;
						cur_pos++;
						if (cur_pos == next.size())
							cur_pos = 0;
					}
				}
			}
			i += next[n_pos];
			n_pos++;
			if (n_pos == next.size())
				n_pos = 0;
		}
		//for (vector<int>::iterator it = result.begin(); it < result.end(); it++)
		//	cout << *it << ",";
		return count;
	}

private:
	vector<int> next;
};

int main()
{
	Solution s;
	clock_t start = clock();
	cout<<endl<<s.countPrimes(1000000)<<endl;
	cout << clock() - start << endl;
	cin.get();
}
