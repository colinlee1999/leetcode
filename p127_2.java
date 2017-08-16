import java.util.*;

public class p127_2 {
    public class Solution {
        public int ladderLength(String beginWord, String endWord, List<String> wordList) {
            if (beginWord.equals(endWord)) return 1;
            HashSet<String> left = new HashSet<>();
            HashSet<String> right = new HashSet<>();
            HashSet<String> canUse = new HashSet<>();
            canUse.addAll(wordList);
            if (!canUse.contains(endWord)) return 0;
            int steps = 1;
            left.add(beginWord);
            right.add(endWord);
            while (!left.isEmpty()) {
                ++steps;
                for (String s : left) canUse.remove(s);
                for (String s : right) canUse.remove(s);
                HashSet<String> nextLeft = new HashSet<>();
                for (String s : left) {
                    for (int pos = 0; pos < s.length(); ++pos) {
                        char[] ns = s.toCharArray();
                        for (char ch = 'a'; ch <= 'z'; ++ch) {
                            ns[pos] = ch;
                            String ts = new String(ns);
                            if (right.contains(ts)) return steps;
                            if (canUse.contains(ts)) nextLeft.add(ts);
                        }
                    }
                }
                if (nextLeft.size() <= right.size()) {
                    left = nextLeft;
                } else {
                    left = right;
                    right = nextLeft;
                }
            }
            return 0;
        }
    }
}
