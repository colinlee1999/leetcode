public class p76 {
    public class Solution {
        public String minWindow(String s, String t) {
            int left, right;
            int[] tBasis = new int[256];
            int[] windowBasis = new int[256];
            String result = "";
            left = 0;
            right = 0;
            for (int i = 0; i < t.length(); ++i) ++tBasis[(int) t.charAt(i)];
            for (int i = 0; i < 256; ++i) {
                while (right < s.length() && windowBasis[i] < tBasis[i]) {
                    ++windowBasis[(int) s.charAt(right)];
                    ++right;
                }
                if (windowBasis[i] < tBasis[i]) return result;
            }
            while (left < right && windowBasis[(int) s.charAt(left)] > tBasis[(int) s.charAt(left)]) {
                --windowBasis[(int) s.charAt(left)];
                ++left;
            }
            result = s.substring(left, right);
            while (right < s.length()) {
                ++windowBasis[(int) s.charAt(right)];
                ++right;
                while (left < right && windowBasis[(int) s.charAt(left)] > tBasis[(int) s.charAt(left)]) {
                    --windowBasis[(int) s.charAt(left)];
                    ++left;
                }
                if (right - left < result.length())
                    result = s.substring(left, right);
            }
            return result;
        }
    }
}
