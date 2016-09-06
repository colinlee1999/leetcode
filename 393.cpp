#include "iostream"
#include "vector"
#include "set"
#include "map"
#include <algorithm>
using namespace std;
#define INT_MIN (1<<31)
#define INT_MAX (~INT_MIN)

class Solution {
public:
	bool validUtf8(vector<int>& data) {
		int mask = (1 << 8) - 1;
		vector<int> initial_mask(4, 0);
		vector<int> initial_target(4, 0);
		initial_mask[0] = 128;
		initial_mask[1] = 224;
		initial_mask[2] = 240;
		initial_mask[3] = 248;
		initial_target[0] = 0;
		initial_target[1] = 192;
		initial_target[2] = 224;
		initial_target[3] = 240;
		int following_mask = 192;
		int following_target = 128;
		int dlen = data.size();
		int still = 0;
		for (int i = 0; i < dlen; i++)
		{
			int temp = data[i] & mask;
			// cout<<"++++++++++++"<<endl;
			// cout<<temp<<endl;
			// cout<< (temp & initial_mask[1])<<endl;
			if (still)
			{
				// cout << "==============" << endl;

				// cout << temp << endl;
				// cout << (temp & following_mask) << endl;
				// cout << following_target << endl;
				if ((temp & following_mask) == following_target)
					still--;
				else return false;
			}
			else
			{
				bool found = false;
				for (int j = 0; j < 4; j++)
					if ((temp & initial_mask[j]) == initial_target[j])
					{
						found = true;
						still = j;
						break;
					}
				if (!found) return false;
			}
		}
		return still == 0;
	}
};

int main()
{
	vector<int> v;
	// v.push_back(197);
	// v.push_back(130);
	// v.push_back(1);
	v.push_back(235);
	v.push_back(140);
	v.push_back(4);
	Solution s;
	cout << s.validUtf8(v) << endl;
    cin.get();
}
