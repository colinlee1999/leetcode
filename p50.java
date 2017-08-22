public class p50 {
    class Solution {
        public double myPow(double x, int n) {
            double s = 1;
            double t = x;
            long m = n;
            if (m < 0) {
                m = -m;
                t = 1 / t;
            }
            while (m > 0) {
                if ((m & 1) == 1) s *= t;
                t *= t;
                m /= 2;
            }
            return s;
        }
    }
}
