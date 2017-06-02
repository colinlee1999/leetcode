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
	bool isPerfectSquare(int num) {
		if (num <= 1) return true;
		int left, right, mid;
		left = 1;
		right = num;
		while (left + 1 < right)
		{
			mid = left + (right - left) / 2;
			if (num / mid < mid) right = mid;
			else left = mid;
		}
		if (left*left == num) return true;
		else return false;
	}
};

int main()
{
    cin.get();
}
