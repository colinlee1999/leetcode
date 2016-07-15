#include "iostream"
#include "vector"
#include "set"
#include <sstream>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
		istringstream is1(version1), is2(version2);
		vector<int> v1, v2;
		int temp;
		while (is1)
		{
			is1 >> temp;
			v1.push_back(temp);
			is1.ignore(1, '.');
		}
		while (is2)
		{
			is2 >> temp;
			v2.push_back(temp);
			is2.ignore(1, '.');
		}
		int i;
		for (i = 0; i < min(v1.size(), v2.size()); i++)
		{
			if (v1[i] > v2[i]) return 1;
			else if (v1[i] < v2[i]) return -1;
		}
		if (v1.size() > v2.size())
		{
			for (; i < v1.size(); i++)
				if (v1[i] != 0) return 1;
		}
		else if (v1.size() < v2.size())
		{
			for (; i < v2.size(); i++)
				if (v2[i] != 0) return -1;
		}
		return 0;
    }
};

int main()
{
    Solution s;
    cin.get();
}
