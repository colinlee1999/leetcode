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
		int last = 11;
		for (int i = 13; i <= 221; i++)
		{
			if (i % 2 == 0) continue;
			if (i % 3 == 0) continue;
			if (i % 5 == 0) continue;
			if (i % 7 == 0) continue;
			next.push_back(i - last);
			last = i;
		}
	}

	int countPrimes(int n) {
		if (n <= 2) return 0;
		if (n <= 3) return 1;
		if (n <= 5) return 2;
		if (n <= 7) return 3;
		if (n <= 11) return 4;
		vector<bool> isprime(n, true);
		int upper = (int)sqrt(n);
		int count = 4;
		//vector<int> result;
		int n_pos = 0;
		for (int i = 11; i < n;)
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
	cout<<s.countPrimes(10)<<endl;
	cout<<s.countPrimes(100)<<endl;
	cout<<s.countPrimes(1000)<<endl;
	cout<<s.countPrimes(10000)<<endl;
	cout<<s.countPrimes(100000)<<endl;
	cout<<s.countPrimes(1000000)<<endl;
	cout << clock() - start << endl;
	cin.get();
}
