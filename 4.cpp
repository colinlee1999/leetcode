#include "iostream"
#include "vector"
#include "set"
#include <sstream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int nlen1 = nums1.size();
		int nlen2 = nums2.size();
		int N = nums1.size() + nums2.size();
		int equal = (N - 1) / 2;
		int pos;
		if (N & 1)
		{
			if (find_median(nums1, nums2, pos))
				return nums1[pos];
			find_median(nums2, nums1, pos);
			return nums2[pos];
		}
		else
		{
			int num_1, num_2;
			if (find_median(nums1, nums2, pos))
			{
				num_1 = nums1[pos];
				if (equal - pos >= 0 && equal - pos < nlen2)
				{
					//if (test(nums2, nums1, equal - pos) == 0)
					//	num_2 = nums2[equal - pos];
					if (num_1 == nums2[equal - pos])
						num_2 = nums2[equal - pos];
					if (num_1 > nums2[equal - pos])
					{
						if (pos > 0) num_2 = max(nums2[equal - pos], nums1[pos - 1]);
						else num_2 = nums2[equal - pos];
					}
					else
					{
						if (pos + 1 < nlen1) num_2 = min(nums2[equal - pos], nums1[pos + 1]);
						else num_2 = nums2[equal - pos];
					}
				}
				else
				{
					if (equal < pos)
						num_2 = nums1[pos - 1];
					else
						num_2 = nums1[pos + 1];
				}
				//if (equal - pos+1 >= 0 && equal - pos+1 < nums2.size())
				//	if (test(nums2, nums1, equal - pos+1) == 0)
				//		num_2 = nums2[equal - pos+1];
			}
			else
			{
				find_median(nums2, nums1, pos);
				num_1 = nums2[pos];
				if (pos + 1 < nlen2)
					if (test(nums2, nums1, pos + 1) == 0)
						num_2 = nums2[pos + 1];
				if (pos > 0)
					if (test(nums2, nums1, pos - 1) == 0)
						num_2 = nums2[pos - 1];
			}
			return (0.0 + num_1 + num_2) / 2;
		}		
    }

private:
	bool find_median(vector<int>& nums1, vector<int>& nums2, int & pos)
	{
		if (nums1.size() == 0) return false;
		int N = nums1.size() + nums2.size();
		int equal = (N-1) / 2;
		int left = 0;
		int right = nums1.size();
		int mid;
		while (left + 1 < right)
		{
			mid = left + (right - left) / 2;
			int temp = test(nums1, nums2, mid);
			if (temp > 0) right = mid;
			else if (temp < 0) left = mid;
			else
			{
				left = mid;
				right = left + 1;
			}
		}
		if (test(nums1, nums2, left) == 0)
		{
			pos = left;
			return true;
		}
		else
			return false;
	}

	int test(vector<int>& nums1, vector<int>& nums2, int pos)
	{
		int nlen1 = nums1.size();
		int nlen2 = nums2.size();
		int N = nlen1 + nlen2;
		int equal = (N-1) / 2;
		if (nlen2 < (equal - pos))
			return -1; // ensure that nums2 have enough numbers
		if (N & 1)
		{
			if (equal < pos) return 1; // ensure that nums1 do not provide too many numbers on the smaller side
			if ((nlen2 > equal - pos) && nums1[pos] > nums2[equal - pos]) return 1; // ensure that median is not too large
		}
		else
		{
			if (equal + 1 < pos) return 1; // ensure that nums1 do not provide too many numbers on the smaller side
			if ((nlen2 > equal - pos +1) && nums1[pos] > nums2[equal - pos + 1]) return 1; // ensure that median is not too large
		}
		if ((equal - pos - 1 >= 0) && (nums1[pos] < nums2[equal - pos - 1])) return -1; // ensure that median is not too small
		return 0;
	}
};

int main()
{
	int myint[] = { 3,4 };
	vector<int> v1(myint, myint + sizeof(myint) / sizeof(int));
	int myint2[] = {  };
	vector<int> v2(myint2, myint2 + sizeof(myint2) / sizeof(int));
	// for (auto it : v1)
	// 	cout<<it<<' ';
	// cout<<endl;
	Solution s;
	cout << s.findMedianSortedArrays(v1, v2) << endl;
    cin.get();
}
