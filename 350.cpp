#include "iostream"
#include "vector"
#include "set"
#include "map"
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size())
			nums1.swap(nums2);
		map<int, int> m1;
		map<int, int>::iterator iter;
		for (vector<int>::iterator it = nums1.begin(); it != nums1.end(); ++it)
		{
			iter = m1.find(*it);
			if (iter == m1.end())
			{
				m1.insert(pair<int,int>(*it,1));
			}
			else
			{
				iter->second++;
			}
		}
		vector<int> result;
		for (vector<int>::iterator it = nums2.begin(); it != nums2.end(); ++it)
		{
			iter = m1.find(*it);
			if (iter != m1.end())
			{
				result.push_back(*it);
				iter->second--;
				if (iter->second == 0)
				{
					m1.erase(iter);
				}
			}
		}
		return result;
    }
};

int main()
{
    Solution s;
	int myints[] = { 1,2,2,1 };
	vector<int> nums1(myints, myints + sizeof(myints) / sizeof(int));
	int myints2[] = { 2,2 };
	vector<int> nums2(myints2, myints2 + sizeof(myints2) / sizeof(int));
	vector<int> nums = s.intersect(nums1, nums2);
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
		cout << *it << ' ';
    cin.get();
}
