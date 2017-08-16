import java.util.*;

public class p127 {
    public class Solution {
        public int ladderLength(String beginWord, String endWord, List<String> wordList) {
            HashMap<Integer, String> hmi = new HashMap<>();
            HashMap<String, Integer> hms = new HashMap<>();
            int count = 0;
            wordList.add(beginWord);
            for (String s :
                    wordList) {
                if (!hms.containsKey(s)) {
                    hmi.put(count, s);
                    hms.put(s, count);
                    ++count;
                }
            }
            int begin = hms.get(beginWord);
            int end = hms.getOrDefault(endWord, -1);
            if (begin == end || end == -1) return 0;

            List<List<Integer>> next = new ArrayList<List<Integer>>();
            for (int i = 0; i < count; ++i)
                next.add(new ArrayList<Integer>());
            for (int i = 0; i < count; ++i) {
                for (int j = i + 1; j < count; ++j) {
                    if (check(hmi.get(i), hmi.get(j))) {
                        next.get(i).add(j);
                        next.get(j).add(i);
                    }
                }
            }

            LinkedList<Integer> q = new LinkedList<>();
            LinkedList<Integer> steps = new LinkedList<>();
            boolean[] b = new boolean[count];
            Arrays.fill(b, false);
            q.add(begin);
            steps.add(1);
            b[begin] = true;
            while (!q.isEmpty()) {
                int cur = q.poll();
                int curSteps = steps.poll();
                for (Integer i :
                        next.get(cur)) {
                    if (!b[i]) {
                        if (i == end) {
                            return curSteps + 1;
                        }
                        b[i] = true;
                        q.addLast(i);
                        steps.add(curSteps + 1);
                    }
                }
            }
            return 0;
        }

        private boolean check(String a, String b) {
            if (a.length() != b.length()) return false;
            int diffCount = 0;
            for (int i = 0; i < a.length(); ++i)
                if (a.charAt(i) != b.charAt(i))
                    ++diffCount;
            return diffCount == 1;
        }
    }
}
