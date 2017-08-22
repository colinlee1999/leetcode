import java.util.ArrayList;
import java.util.List;

public class p57 {
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
        public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
            List<Interval> result = new ArrayList<>();
            int cur = 0;
            int len = intervals.size();
            for (cur = 0; cur < len; ++cur) {
                if (intervals.get(cur).end < newInterval.start) {
                    result.add(intervals.get(cur));
                } else {
                    break;
                }
            }
            if (cur == len) {
                result.add(newInterval);
            } else {
                int newStart = Integer.min(newInterval.start, intervals.get(cur).start);
                int newEnd = newInterval.end;
                for (; cur < len; ++cur) {
                    if (intervals.get(cur).start > newEnd) {
                        result.add(new Interval(newStart, newEnd));
                        break;
                    } else {
                        newEnd = Integer.max(newEnd, intervals.get(cur).end);
                    }
                }
                if (cur == len)
                    result.add(new Interval(newStart, newEnd));
                else for (; cur < len; ++cur)
                    result.add(intervals.get(cur));
            }
            return result;
        }
    }
}
