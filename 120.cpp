#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <sstream>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		if (triangle.empty()) return 0;
		if (triangle[0].empty()) return 0;
		int m = triangle.size();
		for (int i = 1; i < m; i++)
		{
			triangle[i][0] = triangle[i - 1][0] + triangle[i][0];
			triangle[i][i] = triangle[i - 1][i - 1] + triangle[i][i];
			for (int j = 1; j < i; j++)
				triangle[i][j] = min(triangle[i - 1][j - 1], triangle[i - 1][j]) + triangle[i][j];
		}
		int result = INT_MAX;
		for (int i = 0; i < m; i++)
			result = min(result, triangle[m - 1][i]);
		return result;
	}
};

int main()
{
    Solution s;
    cin.get();
}
