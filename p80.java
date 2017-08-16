public class p80 {
    public class Solution {
        public int removeDuplicates(int[] nums) {
            if (nums.length <=2) return nums.length;
            int len = 2;
            int first = nums[0];
            int second = nums[1];
            for (int i = 2; i < nums.length; ++i) {
                if (!(first == second && second == nums[i])) {
                    first = second;
                    second = nums[i];
                    nums[len] = second;
                    ++len;
                }
            }
            return len;
        }
    }
}
