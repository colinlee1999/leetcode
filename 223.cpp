#include "iostream"
#include "vector"
#include "map"
#include "cmath"
#include <stack>
#include <queue>
#include <sstream>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int area1, area2, area3;
		int W, X, Y, Z;
		area1 = (C - A)*(D - B);
		area2 = (G - E)*(H - F);
		W = max(A, E);
		X = max(B, F);
		Y = min(C, G);
		Z = min(D, H);
		if (W < Y && X < Z) area3 = (Y - W)*(Z - X);
		else area3 = 0;
		return area1 + area2 - area3;
    }
};

int main()
{
    cin.get();
}
