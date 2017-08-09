public class p209 {
    public class Solution {
        public int minSubArrayLen(int s, int[] nums) {
            int left = 0;
            int right = 0;
            int len = nums.length;
            int sum = 0;
            int result = Integer.MAX_VALUE;
            while (right < len) {
                sum += nums[right];
                ++right;
                while (sum - nums[left] >= s) {
                    sum -= nums[left];
                    ++left;
                }
                if (sum >= s) {
                    result = Integer.min(result, right - left);
                }
            }
            if (left == 0 && right == len && sum < s) {
                return 0;
            } else {
                return result;
            }
        }
    }
}
