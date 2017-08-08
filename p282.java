import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class p282 {
    public class Solution {
        public List<String> addOperators(String num, int target) {
            List<String> result = new ArrayList<String>();
            if (num.isEmpty()) return result;
            Elements[][] cache = new Elements[num.length()][num.length() + 1];
            for (int j = 1; j <= num.length(); ++j) {
                for (int i = j - 1; i >= 0; --i) {
                    if (cache[i][j] == null) cache[i][j] = new Elements();
                    String tmpStr = num.substring(i, j);
                    long val = Long.parseLong(tmpStr);
                    if (!(tmpStr.length() > 1 && tmpStr.charAt(0) == '0'))
                        cache[i][j].vec.add(new Element(tmpStr, val));
                    for (int k = i + 1; k < j; ++k) {
                        tmpStr = num.substring(k, j);
                        val = Long.parseLong(tmpStr);
                        if (!(tmpStr.length() > 1 && tmpStr.charAt(0) == '0')) {
                            for (Element e :
                                    cache[i][k].vec) {
                                cache[i][j].vec.add(new Element(e.expr + "*" + tmpStr, e.val * val));
                            }
                        }
                    }
                }
            }
            dfs(result, cache, num, target, 1, 0, 1, 0, "");
            return result;
        }

        private void dfs(List<String> result, Elements[][] cache, String num, long target, long sign, int lastPos, int curPos, long curVal, String curStr) {
            if (curPos > num.length()) {
                if (curVal == target) {
                    result.add(curStr.substring(1));
                }
            } else {
                for (Element e :
                        cache[lastPos][curPos].vec) {
                    long tmpVal = curVal + sign * e.val;
                    String tmpStr = curStr + (sign == 1 ? "+" : "-");
                    tmpStr += e.expr;
                    dfs(result, cache, num, target, 1, curPos, curPos + 1, tmpVal, tmpStr);
                    if (curPos < num.length())
                        dfs(result, cache, num, target, -1, curPos, curPos + 1, tmpVal, tmpStr);
                }
                if (curPos < num.length()) {
                    dfs(result, cache, num, target, sign, lastPos, curPos + 1, curVal, curStr);
                }
            }
        }

        private class Elements {
            public List<Element> vec;

            public Elements() {
                vec = new ArrayList<Element>();
            }
        }

        private class Element {
            public String expr;
            public long val;

            public Element(String expr, long val) {
                this.expr = expr;
                this.val = val;
            }
        }
    }
}
