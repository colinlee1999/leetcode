#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_map>
using namespace std;

class NumArray {
public:
	NumArray(vector<int> &nums) {
		sums.push_back(0);
		for (vector<int>::iterator it = nums.begin(); it < nums.end(); it++)
		{
			sums.push_back(sums.back() + *it);
		}
	}

	int sumRange(int i, int j) {
		return sums[j + 1] - sums[i];
	}

private:
	vector<int> sums;
};

int main()
{
	vector<int> v;
	v.push_back(-2);
	v.push_back(0);
	v.push_back(3);
	v.push_back(-5);
	v.push_back(2);
	v.push_back(-1);
	NumArray s(v);
	cout << s.sumRange(0, 2) << endl;
	cout << s.sumRange(2, 5) << endl;
	cout << s.sumRange(0, 5) << endl;
	cin.get();
}
