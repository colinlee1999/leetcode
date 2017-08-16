import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;

public class p90 {
    public class Solution {
        HashSet<List<Integer>> hs;

        public List<List<Integer>> subsetsWithDup(int[] nums) {
            Arrays.sort(nums);
            List<Integer> cur = new LinkedList<>();
            hs = new HashSet<>();
            dfs(nums, 0, cur);
            List<List<Integer>> result = new LinkedList<>();
            for (List<Integer> l : hs) {
                result.add(l);
            }
            return result;
        }

        private void dfs(int[] nums, int pos, List<Integer> cur) {
            if (pos == nums.length) {
                if (!hs.contains(cur)) {
                    hs.add(new LinkedList<>(cur));
                }
            } else {
                dfs(nums, pos + 1, cur);
                ((LinkedList) cur).addLast(nums[pos]);
                dfs(nums, pos + 1, cur);
                ((LinkedList) cur).removeLast();
            }
        }
    }
}
