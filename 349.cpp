#include "iostream"
#include "vector"
#include "set"
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1;
        set<int> set_result;

		for (vector<int>::iterator it = nums1.begin(); it != nums1.end(); ++it)
			s1.insert(*it);
		for (vector<int>::iterator it = nums2.begin(); it != nums2.end(); ++it)
		{
			if (s1.find(*it)!=s1.end())
			{
				set_result.insert(*it);
			}
		}

        vector<int> result;
        for (set<int>::iterator it = set_result.begin(); it != set_result.end(); ++it)
            result.push_back(*it);
        return result;
    }
};

int main()
{
    Solution s;
    int myints[] = {1,2,2,1};
    vector<int> nums1(myints, myints + sizeof(myints) / sizeof(int));
    int myints2[] = {2,2};
    vector<int> nums2(myints2, myints2 + sizeof(myints2) / sizeof(int));
    vector<int> nums=s.intersection(nums1,nums2);
    for (vector<int>::iterator it = nums.begin() ; it != nums.end(); ++it)
        cout << *it <<' ';
    cin.get();
}
