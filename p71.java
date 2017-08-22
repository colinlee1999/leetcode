import java.util.LinkedList;

public class p71 {
    class Solution {
        public String simplifyPath(String path) {
            String[] strs = path.split("/");
            LinkedList<String> ls = new LinkedList<>();
            for (String s : strs) {
                if (!(s.length() == 0 || s.equals("."))) {
                    if (s.equals("..")) {
                        if (!ls.isEmpty()) ls.removeLast();
                    } else {
                        ls.add(s);
                    }
                }
            }
            StringBuilder result = new StringBuilder();
            if (ls.isEmpty()) result.append("/");
            else for (String s : ls) {
                result.append('/');
                result.append(s);
            }
            return result.toString();
        }
    }
}
