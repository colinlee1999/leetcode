import java.util.ArrayList;
import java.util.List;

public class p68 {
    class Solution {
        public List<String> fullJustify(String[] words, int maxWidth) {
            ArrayList<String> result = new ArrayList<>();
            int st = 0;
            int ed = 0;
            while (ed < words.length) {
                int curLen = words[ed].length();
                ++ed;
                while (ed < words.length && curLen + 1 + words[ed].length() <= maxWidth) {
                    curLen += 1 + words[ed].length();
                    ++ed;
                }
                int gap = 1;
                int remainder = 0;
                if (ed != words.length && ed - st > 1) {
                    int numerator = maxWidth - curLen + ed - st - 1;
                    int denominator = ed - st - 1;
                    gap = numerator / denominator;
                    remainder = numerator % denominator;
                }
                StringBuilder sb = new StringBuilder();
                sb.append(words[st]);
                curLen = words[st].length();
                ++st;
                while (st < ed) {
                    for (int i = 0; i < gap; ++i)
                        sb.append(' ');
                    curLen += gap;
                    if (remainder > 0) {
                        sb.append(' ');
                        ++curLen;
                        --remainder;
                    }
                    sb.append(words[st]);
                    curLen += words[st].length();
                    ++st;
                }
                for (; curLen < maxWidth; ++curLen)
                    sb.append(' ');
                result.add(sb.toString());
            }
            return result;
        }
    }
}
