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

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef stack<PII> SPII;

class Solution {
public:
	vector<int> exclusiveTime(int n, vector<string>& logs) {
		VI result(n, 0);
		SPII spii;
		for (auto it : logs) {
			char buffer[6];
			int id, time;
			for (auto chp = it.begin(); chp != it.end(); ++chp) {
				if (*chp == ':') *chp = ' ';
			}
			sscanf(it.c_str(), "%d %s %d", &id, buffer, &time);
			string s(buffer);
			if (s == "start") {
				if (!spii.empty()) {
					int running_id = spii.top().first;
					int duration = time - spii.top().second;
					result[running_id] += duration;
				}
				spii.emplace(id, time);
			}
			else {
				int running_id = spii.top().first;
				int duration = time - spii.top().second + 1;
				result[running_id] += duration;
				spii.pop();
				if (!spii.empty()) spii.top().second = time + 1;
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	cin.get();
}
