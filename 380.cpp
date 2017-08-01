#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
#include <utility>

#include <cstdio>
using namespace std;

typedef unordered_map<int, int> UMAP_INT_INT;
typedef vector<int> VI;

class RandomizedSet {
public:
	/** Initialize your data structure here. */
	RandomizedSet() {
		nums.clear();
		umap.clear();
	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (umap.find(val) == umap.end()) {
			umap[val] = nums.size();
			nums.push_back(val);
			return true;
		}
		else {
			return false;
		}
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (umap.find(val) == umap.end()) {
			return false;
		}
		else {
			if (umap[val] + 1 != nums.size()) {
				umap[nums.back()] = umap[val];
				nums[umap[val]] = nums.back();
			}
			umap.erase(val);
			nums.pop_back();
			return true;
		}
	}

	/** Get a random element from the set. */
	int getRandom() {
		if (!nums.empty()) {
			return nums[rand() % nums.size()];
		}
		else {
			return 0;
		}
	}

private:
	VI nums;
	UMAP_INT_INT umap;
};

int main()
{
	Solution s;
	cin.get();
}
