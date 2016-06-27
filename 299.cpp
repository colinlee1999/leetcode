#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
#include <queue>
#include <sstream>
using namespace std;

class Solution {
public:
	string getHint(string secret, string guess) {
		vector<int> v(10, 0);
		vector<bool> b(secret.length(), false);
		int A = 0, B = 0;
		for (int i = 0; i < secret.length(); i++)
		{
			if (secret[i] == guess[i])
			{
				b[i] = true;
				A++;
			}
			else
			{
				v[secret[i] - '0']++;
			}
		}
		for (int i = 0; i < guess.length(); i++)
		{
			if (!b[i])
			{
				if (v[guess[i] - '0']>0)
				{
					B++;
					v[guess[i] - '0']--;
				}
			}
		}
		ostringstream result;
		result << A << 'A' << B << 'B';
		return result.str();
	}
};

int main()
{
    cin.get();
}
