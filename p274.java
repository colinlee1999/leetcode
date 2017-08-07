import java.util.List;

public class p274 {
    public class Solution {
        public int hIndex(int[] citations) {
            int[] counter = new int[citations.length + 1];
            for (int it :
                    citations) {
                it = it > citations.length ? citations.length : it;
                ++counter[it];
            }
            int tmp = 0;
            int i = 0;
            for (i = citations.length; i > 0; --i) {
                tmp += counter[i];
                if (tmp >= i) {
                    break;
                }
            }
            return i;
        }
    }
}
