#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
		vector<int>::iterator head = nums.begin();
		while (head != nums.end() && *head != 0) head++;
		if (head == nums.end()) return;
		vector<int>::iterator tail = head;
		while (++head != nums.end())
		{
			if (*head != 0)
			{
				*tail = *head;
				*head = 0;
				tail++;
			}
		}
    }
};

int main()
{
    Solution s;
    int myints[] = {1};
    vector<int> nums(myints, myints + sizeof(myints) / sizeof(int));
    s.moveZeroes(nums);
    for (vector<int>::iterator it = nums.begin() ; it != nums.end(); ++it)
    	cout << *it <<' ';
    cout<<endl;
    cin.get();
}
