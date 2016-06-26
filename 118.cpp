#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
		vector<vector<int> > result;
		int count=0;
		while (count < numRows)
		{
			result.push_back(vector<int>());
			result[count].push_back(1);
			for (int i = 1; i < count; i++)
			{
				result[count].push_back(result[count - 1][i] + result[count - 1][i - 1]);
			}
			if (count > 0) result[count].push_back(1);
			count++;
		}
		return result;
    }
};

int main()
{
    cin.get();
}
