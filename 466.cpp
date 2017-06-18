#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <sstream>
#include <set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

struct ele {
	ele() {}
	ele(int consumed, int result) {
		cur_consumed = consumed;
		cur_result = result;
	}

	int cur_consumed;
	int cur_result;
};

class Solution {
public:
	int getMaxRepetitions(string s1, int n1, string s2, int n2) {
		int s1len = s1.length();
		int s2len = s2.length();
		vector<int> num(s1len + 1, 0);
		vector<int> end_pos(s1len + 1, 0);
		vector<int> consumed(s1len + 1, 0);
		for (int i = 1; i <= s1len; i++) {
			match(s1, s2, i, num[i], end_pos[i], consumed[i]);
		}
		//cout << s1 << endl;
		num[0] = num.back();
		end_pos[0] = end_pos.back();
		consumed[0] = consumed.back();
		//for (int i = 0; i < s1len; i++) {
		//	printf("%d\t%d\t%d\t%d\n", i, num[i], end_pos[i], consumed[i]);
		//}
		map<int, ele> start_points;
		int result = 0;
		int cur_consumed = 0;
		int cur_pos = s1len;
		int maximum = s1len * n1;
		bool found = false;
		while (cur_consumed < maximum) {
			//printf("%d\t%d\t%d\n", cur_pos, cur_consumed, result);
			if (end_pos[cur_pos] == -1) {
				break;
			}
			else {
				if (start_points.find(cur_pos) != start_points.end()) {
					found = true;
					break;
				}
				else {
					if (cur_consumed + consumed[cur_pos] <= maximum) {
						start_points[cur_pos] = ele(cur_consumed, result);
						result++;
					}
					else {
						break;
					}
				}
				cur_consumed += consumed[cur_pos];
				cur_pos = end_pos[cur_pos];
			}
		}
		//cout << found << endl;
		//printf("%d\t%d\t%d\n", cur_pos, cur_consumed, result);
		if (found) {
			int tmp = (maximum - cur_consumed) / (cur_consumed - start_points[cur_pos].cur_consumed);
			result += tmp * (result - start_points[cur_pos].cur_result);
			cur_consumed += tmp * (cur_consumed - start_points[cur_pos].cur_consumed);
			while (cur_consumed < maximum) {
				if (end_pos[cur_pos] == -1) {
					break;
				}
				else {
					if (cur_consumed + consumed[cur_pos] <= maximum) {
						result++;
					}
					else {
						break;
					}
					cur_consumed += consumed[cur_pos];
					cur_pos = end_pos[cur_pos];
				}
			}
		}
		return result / n2;
	}

private:
	void match(string & s1, string & s2, int start_pos, int & n1, int & end_pos, int & consumed) {
		int s1len = s1.length();
		int s2len = s2.length();
		n1 = 0;
		bool found = false;
		int pos1 = start_pos;
		int pos2 = 0;
		consumed = 0;
		while (n1 <= s2len) {
			while (pos1 < s1.length() && s1[pos1] != s2[pos2]) {
				++pos1;
				++consumed;
			}
			if (pos1 == s1.length()) {
				pos1 = 0;
				++n1;
				continue;
			}
			else {
				++pos1;
				++consumed;
				++pos2;
				if (pos2 == s2len) {
					found = true;
					break;
				}
			}
		}
		if (found) {
			n1 = n1;
			end_pos = pos1;
		}
		else {
			n1 = end_pos = -1;
		}
	}
};

int main()
{
	Solution s;
	cout << s.getMaxRepetitions("nlhqgllunmelayl", 2, "lnl", 1) << endl;
	cin.get();
}
