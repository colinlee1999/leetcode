#include "iostream"
#include "vector"
#include "set"
#include <unordered_map>
#include <stack>
#include <ctime>
#include <random>
using namespace std;

class Solution {
public:
	bool isPowerOfFour(int num) {
		if (num < 1) return false;
		if ((num & (num - 1)) != 0) return false;
		return num % 3 == 1;
	}
};

int main()
{
    cin.get();
}
