import java.util.HashSet;
import java.util.Iterator;
import java.util.List;

public class p139 {
    public class Solution {
        public boolean wordBreak(String s, List<String> wordDict) {
            HashSet<String> hs = new HashSet<>();
            int maxLen = 0;
            for (String str :
                    wordDict) {
                hs.add(str);
                maxLen = Integer.max(maxLen, str.length());
            }
            HashSet<Integer> hsi = new HashSet<>();
            hsi.add(0);
            for (int pos = 1; pos <= s.length(); ++pos) {
                boolean found = false;
                for (Iterator<Integer> it = hsi.iterator(); it.hasNext(); ) {
                    int i = it.next();
                    if (pos - maxLen > i) {
                        it.remove();
                    } else {
                        if (hs.contains(s.substring(i, pos))) {
                            found = true;
                            break;
                        }
                    }
                }
                if (found) hsi.add(pos);
            }
            return hsi.contains(s.length());
        }
    }
}
