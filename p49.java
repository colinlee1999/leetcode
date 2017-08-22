import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

public class p49 {
    class Solution {
        public List<List<String>> groupAnagrams(String[] strs) {
            List<List<String>> result = new ArrayList<>();
            HashMap<String, Integer> hms = new HashMap<>();
            int counter = 0;
            for (String s : strs) {
                char[] ch = s.toCharArray();
                Arrays.sort(ch);
                String ts = new String(ch);
                if (!hms.containsKey(ts)) {
                    hms.put(ts, counter);
                    result.add(new ArrayList<>());
                    ++counter;
                }
                result.get(hms.get(ts)).add(s);
            }
            return result;
        }
    }
}
