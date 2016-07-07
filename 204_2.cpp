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
		if (n < 3) return 0;
		vector<bool> isprime(n, true);
		int count = 1;
		int upper = (int)sqrt(n) + 1;
		for (int i = 3; i < n; i += 2)
		{
			if (!isprime[i]) continue;
			count++;
			if (i > upper) continue;
			for (int j = i*i; j < n; j += (i + i))
				isprime[j] = false;
		}
		return count;
	}
};

int main()
{
	Solution s;
	clock_t start = clock();
	cout<<s.countPrimes(1000000)<<endl;
	cout << clock() - start << endl;
	cin.get();
}
