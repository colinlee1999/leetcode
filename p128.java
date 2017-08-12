import java.util.HashMap;

public class p128 {
    public class Solution {
        public int longestConsecutive(int[] nums) {
            HashMap<Integer, Integer> startAt = new HashMap<>();
            HashMap<Integer, Integer> endAt = new HashMap<>();
            int result = 0;
            for (int it :
                    nums) {
                if (!startAt.containsKey(it)) {
                    if (startAt.containsKey(it + 1)) {
                        startAt.put(it, startAt.get(it + 1) + 1);
                    } else {
                        startAt.put(it, 1);
                    }
                    if (endAt.containsKey(it - 1)) {
                        endAt.put(it, endAt.get(it - 1) + 1);
                    } else {
                        endAt.put(it, 1);
                    }
                    int curLen = startAt.get(it) + endAt.get(it) - 1;
                    if (startAt.containsKey(it + 1)) {
                        endAt.put(it + startAt.get(it + 1), curLen);
                    }
                    if (endAt.containsKey(it - 1)) {
                        startAt.put(it - endAt.get(it - 1), curLen);
                    }
                    result = Integer.max(result, curLen);
                }
            }
            return result;
        }
    }
}
