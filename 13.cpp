#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	Solution() {
		alpha.insert(pair<char,int>('M',1000));
		alpha.insert(pair<char,int>('D',500));
		alpha.insert(pair<char,int>('C',100));
		alpha.insert(pair<char,int>('L',50));
		alpha.insert(pair<char,int>('X',10));
		alpha.insert(pair<char,int>('V',5));
		alpha.insert(pair<char,int>('I',1));

		order_string = "MDCLXVI";
	}

    int romanToInt(string s) {
		if (s.length() > 0)
		{
			size_t pos;
			for (string::iterator it = order_string.begin(); it != order_string.end(); it++)
			{
				if ((pos = s.find(*it)) != s.npos) break;
			}
			return alpha[s[pos]] - romanToInt(s.substr(0, pos)) + romanToInt(s.substr(pos + 1));
		}
		else
		{
			return 0;
		}return 0;		
    }

private:
	map<char, int> alpha;
	string order_string;
};

int main()
{
    Solution s;
    cout<<s.romanToInt("DCXLVIII")<<endl;
    cout<<s.romanToInt("MMDXLIX")<<endl;
    cout<<s.romanToInt("MCMXLIV")<<endl;
    cout<<s.romanToInt("MCMXCIX")<<endl;
    cin.get();
}
