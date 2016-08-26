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
	int maxProduct(vector<string>& words) {
		vector<int> hash;
		for (auto wit : words)
		{
			int temp = 0;
			for (auto ch : wit)
				temp |= 1 << (ch - 'a');
			hash.push_back(temp);
		}
		int wlen = words.size();
		int result = 0;
		for (int i = 0; i < wlen; i++)
			for (int j = i + 1; j < wlen; j++)
				if (((hash[i] & hash[j]) == 0) && (int)words[i].length()*(int)words[j].length()>result)
					result = (int)words[i].length()*(int)words[j].length();
		return result;
	}
};

int main()
{
    cin.get();
}
