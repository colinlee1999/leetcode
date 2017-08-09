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
using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

Point pivot;

int area2(Point a, Point b, Point c) {
	return a.x * b.y - a.y * b.x + b.x * c.y - b.y * c.x + c.x * a.y - c.y * a.x;
}

int dist2(Point a, Point b) {
	int dx = a.x - b.x;
	int dy = a.y - b.y;
	return dx * dx + dy * dy;
}

struct {
	bool operator() (Point a, Point b) {
		if (area2(pivot, a, b) == 0) {
			return dist2(pivot, a) < dist2(pivot, b);
		}
		int d1x = a.x - pivot.x;
		int d1y = a.y - pivot.y;
		int d2x = b.x - pivot.x;
		int d2y = b.y - pivot.y;
		return (atan2((double)d1y, (double)d1x) - atan2((double)d2y, (double)d2x)) < 0;
	}
} angle_cmp;

int turn(Point p, Point q, Point r) {
	int result = (r.x - q.x) * (p.y - q.y) - (r.y - q.y) *(p.x - q.x);
	if (result < 0) return -1;
	if (result > 0) return 1;
	return 0;
}

bool ccw(Point p, Point q, Point r) {
	return turn(p, q, r) >= 0;
}

class Solution {
public:
	vector<Point> outerTrees(vector<Point>& points) {
		int i, P0 = 0, N = points.size();
		for (i = 1; i < N; i++) {
			if (points[i].y < points[P0].y ||
				(points[i].y == points[P0].y && points[i].x > points[P0].x)) {
				P0 = i;
			}
		}
		Point temp = points[0];
		points[0] = points[P0];
		points[P0] = temp;

		pivot = points[0];
		sort(points.begin() + 1, points.end(), angle_cmp);
		Point p = points.back();
		int cur = N - 2;
		while (cur > 0 && turn(points[cur], p, pivot) == 0)
			--cur;
		++cur;
		reverse(points.begin() + cur, points.end());

		stack<Point> S;
		Point prev, now;
		S.push(points[N - 1]);
		S.push(points[0]);
		
		i = 1;
		while (i < N) {
			now = S.top();
			S.pop();
			prev = S.top();
			S.push(now);
			if (ccw(prev, now, points[i])) {
				S.push(points[i]);
				i++;
			}
			else {
				S.pop();
			}
		}

		vector<Point> ConvexHull;
		while (!S.empty()) {
			ConvexHull.push_back(S.top());
			S.pop();
		}
		ConvexHull.pop_back();
		return ConvexHull;
	}
};

int main()
{
	Solution s;
	cin.get();
}
