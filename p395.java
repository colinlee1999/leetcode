public class p395 {
    public class Solution {
        private int k;
        private int result;

        public int longestSubstring(String s, int k) {
            this.k = k;
            result = 0;
            dfs(s);
            return result;
        }

        private void dfs(String str) {
            if (str.isEmpty())
                return;
            String regex = check(str);
            if (regex.isEmpty()) {
                result = Integer.max(result, str.length());
            } else {
                String[] splitted = str.split("[" + regex + "]");
                for (String subStr :
                        splitted) {
                    dfs(subStr);
                }
            }
        }

        private String check(String str) {
            StringBuilder result = new StringBuilder();
            int[] counter = new int[26];
            for (int i = 0; i < str.length(); ++i) {
                char ch = str.charAt(i);
                ++counter[ch - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                int c = counter[i];
                if (c > 0 && c < k) {
                    result.append((char)(i + 'a'));
                }
            }
            return result.toString();
        }
    }
}
