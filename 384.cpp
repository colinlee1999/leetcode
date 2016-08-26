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
	Solution(vector<int> nums) {
		backup = vector<int>(nums);
		nlen = nums.size();
		srand(time(0));
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return backup;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int> result(backup);
		int temp;
		for (int i = 0; i < nlen; i++)
		{
			while ((temp = rand()) == RAND_MAX);
			int next = (double)temp / RAND_MAX * (nlen - i) + i;
			swap(result[i], result[next]);
		}
		return result;
	}

private:
	vector<int> backup;
	int nlen;
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(nums);
* vector<int> param_1 = obj.reset();
* vector<int> param_2 = obj.shuffle();
*/

int main()
{
    cin.get();
}
