import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;

public class p218 {
    public class Solution {
        public List<int[]> getSkyline(int[][] buildings) {
            List<int[]> result = new ArrayList<int[]>();
            int len = buildings.length;
            if (len == 0) return result;
            List<Event> events = new ArrayList<Event>();
            for (int[] row :
                    buildings) {
                int left = row[0];
                int right = row[1];
                int height = row[2];
                events.add(new Event(left, true, height));
                events.add(new Event(right, false, height));
            }
            events.sort((e1, e2) -> e1.compareTo(e2));
            events.add(new Event(events.get(events.size() - 1).pos + 1, true, 0));
            PriorityQueue<Integer> skyline = new PriorityQueue<Integer>(1, (Integer i1, Integer i2) -> i2 - i1);
            PriorityQueue<Integer> remove = new PriorityQueue<Integer>(1, (Integer i1, Integer i2) -> i2 - i1);
            skyline.add(0);
            int lastPos = -1;
            int lastHeight = 0;
            for (Event e :
                    events) {
                if (e.pos != lastPos) {
                    while (!remove.isEmpty() && skyline.peek().equals(remove.peek())) {
                        skyline.poll();
                        remove.poll();
                    }
                    if (skyline.peek() != lastHeight) {
                        lastHeight = skyline.peek();
                        result.add(new int[]{lastPos, lastHeight});
                    }
                    lastPos = e.pos;
                }
                if (e.push) skyline.add(e.height);
                else remove.add(e.height);
            }
            return result;
        }

        private class Event implements Comparable<Event> {
            public int pos;
            public boolean push;
            public int height;

            public Event(int pos, boolean push, int height) {
                this.pos = pos;
                this.push = push;
                this.height = height;
            }

            @Override
            public int compareTo(final Event e) {
                return this.pos - e.pos;
            }
        }
    }
}
