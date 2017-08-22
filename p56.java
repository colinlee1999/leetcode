import java.util.ArrayList;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;

public class p56 {
    public class Interval {
        int start;
        int end;

        Interval() {
            start = 0;
            end = 0;
        }

        Interval(int s, int e) {
            start = s;
            end = e;
        }
    }

    class Solution {
        public List<Interval> merge(List<Interval> intervals) {
            intervals.sort(new Comparator<Interval>() {
                @Override
                public int compare(Interval o1, Interval o2) {
                    return o1.start - o2.start;
                }
            });
            List<Interval> result = new LinkedList<>();
            long newEnd = Long.MIN_VALUE;
            long newStart = newEnd;
            for (Interval cur : intervals) {
                if (cur.start > newEnd) {
                    if (newEnd != Long.MIN_VALUE)
                        result.add(new Interval((int) newStart, (int) newEnd));
                    newStart = cur.start;
                    newEnd = cur.end;
                } else {
                    newEnd = Long.max(newEnd, cur.end);
                }
            }
            if (newEnd != Long.MIN_VALUE)
                result.add(new Interval((int) newStart, (int) newEnd));
            return result;
        }
    }
}
