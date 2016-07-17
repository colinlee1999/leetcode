#include "iostream"
#include "vector"
#include "set"
#include <sstream>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int N = nums1.size() + nums2.size();
		if (N & 1)
			return findKth(nums1, 0, nums2, 0, N / 2 + 1);
		else
			return (findKth(nums1, 0, nums2, 0, N / 2) + findKth(nums1, 0, nums2, 0, N / 2 + 1)) / 2;
	}

private:
	double findKth(vector<int>& nums1, int pos1, vector<int>&nums2, int pos2, int k)
	{
		if (nums1.size() - pos1 > nums2.size() - pos2)
			return findKth(nums2, pos2, nums1, pos1, k);
		if (nums1.size() == pos1)
			return nums2[k - 1 + pos2];
		if (k == 1)
			return min(nums1[pos1], nums2[pos2]);
		int p1 = min(k / 2, (int)nums1.size() - pos1);
		int p2 = k - p1;
		if (nums1[pos1 + p1 - 1] < nums2[pos2 + p2 - 1]) return findKth(nums1, pos1 + p1, nums2, pos2, k - p1);
		else if (nums1[pos1 + p1 - 1]>nums2[pos2 + p2 - 1]) return findKth(nums1, pos1, nums2, pos2 + p2, k - p2);
		else return nums1[pos1 + p1 - 1];
	}
};

int main()
{
	int myint[] = { 1,3 };
	vector<int> v1(myint, myint + sizeof(myint) / sizeof(int));
	int myint2[] = { 2 };
	vector<int> v2(myint2, myint2 + sizeof(myint2) / sizeof(int));
	// for (auto it : v1)
	// 	cout<<it<<' ';
	// cout<<endl;
	Solution s;
	cout << s.findMedianSortedArrays(v1, v2) << endl;
    cin.get();
}
