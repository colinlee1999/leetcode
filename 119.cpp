#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		if (rowIndex < 0) return vector<int>();
		if (rowIndex == 0) return vector<int>(1, 1);
		vector<int> now, next;
		now = vector<int>(1);
		while (rowIndex > 0)
		{
			next.clear();
			next.push_back(1);
			for (int i = 1;i < now.size();i++)
				next.push_back(now[i - 1] + now[i]);
			next.push_back(1);
			now = next;
			rowIndex--;
		}
		return now;
	}
};

int main()
{
    cin.get();
}
