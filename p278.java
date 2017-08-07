import java.util.List;

public class p278 {
    public class VersionControl {
        boolean isBadVersion(int version) {
            return true;
        }
    }

    public class Solution extends VersionControl {
        public int firstBadVersion(int n) {
            int left = 0;
            int right = n;
            int mid;
            while (left + 1 < right) {
                mid = (right - left) / 2 + left;
                if (isBadVersion(mid)) right = mid;
                else left = mid;
            }
            return right;
        }
    }
}
