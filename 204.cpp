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
using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		vector<bool> isprime(n, true);
		for (int i = 2; i * i < n; i++)
		{
			if (!isprime[i]) continue;
			for (int j = i*i; j < n; j += i)
				isprime[j] = false;
		}
		int count = 0;
		for (int i = 2; i < n; i++)
			if (isprime[i]) count++;
		return count;
	}
};

int main()
{
	Solution s;
	clock_t start = clock();
	cout<<s.countPrimes(100000)<<endl;
	cout << clock() - start << endl;
	cin.get();
}
