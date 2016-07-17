#include "iostream"
#include "vector"
#include "set"
#include <map>
using namespace std;

class Solution {
public:
	Solution() {
		alpha.insert(pair<int, char>(1000, 'M'));
		alpha.insert(pair<int, char>(500, 'D'));
		alpha.insert(pair<int, char>(100, 'C'));
		alpha.insert(pair<int, char>(50, 'L'));
		alpha.insert(pair<int, char>(10, 'X'));
		alpha.insert(pair<int, char>(5, 'V'));
		alpha.insert(pair<int, char>(1, 'I'));

		order_vec.push_back(1000);
		order_vec.push_back(500);
		order_vec.push_back(100);
		order_vec.push_back(50);
		order_vec.push_back(10);
		order_vec.push_back(5);
		order_vec.push_back(1);

		minus.insert(pair<int, int>(1000,100));
		minus.insert(pair<int, int>(500, 100));
		minus.insert(pair<int, int>(100, 10));
		minus.insert(pair<int, int>(50, 10));
		minus.insert(pair<int, int>(10, 1));
		minus.insert(pair<int, int>(5, 1));
	}

    string intToRoman(int num) {
		string result;
		int pos = 0;
		while (pos<order_vec.size())
		{
			if (num >= order_vec[pos] - minus[order_vec[pos]])
			{
				if (num >= order_vec[pos]) return alpha[order_vec[pos]] + intToRoman(num - order_vec[pos]);
				string temps = "";
				temps += alpha.at(minus[order_vec[pos]]);
				temps += alpha.at(order_vec[pos]);
				return temps + intToRoman(num - order_vec[pos] + minus[order_vec[pos]]);
			}
			pos++;
		}
		return "";
    }

private:
	map<int, char> alpha;
	map<int, int> minus;
	vector<int> order_vec;
};

int main()
{
	Solution s;
	cout << s.intToRoman(47) << endl;
    cin.get();
}
