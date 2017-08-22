public class p75 {
    class Solution {
        public void sortColors(int[] nums) {
            int left = 0;
            int right = nums.length - 1;
            for (int i = left; i <= right; ++i) {
                if (nums[i] == 0) {
                    nums[i] = nums[left];
                    nums[left] = 0;
                    ++left;
                } else if (nums[i] == 2) {
                    nums[i] = nums[right];
                    nums[right] = 2;
                    --right;
                    --i;
                }
            }
        }
    }
}
