#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <sstream>
using namespace std;

int guess(int num);

class Solution {
public:
	int guessNumber(int n) {
		int left = 1;
		int right = n;
		int mid;
		while (left < right)
		{
			mid = left + (right - left) / 2;
			int temp = guess(mid);
			if (temp < 0) right = mid;
			else if (temp>0) left = mid + 1;
			else return mid;
		}
		return left;
	}
};

int main()
{
    Solution s;
    cin.get();
}
