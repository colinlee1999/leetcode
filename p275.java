import java.util.List;

public class p275 {
    public class Solution {
        public int hIndex(int[] citations) {
            int tmp = 0;
            for (int i = citations.length - 1; i >= 0; --i) {
                if (citations[i] > tmp) {
                    ++tmp;
                } else {
                    break;
                }
            }
            return tmp;
        }
    }
}
