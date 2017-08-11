import java.util.LinkedHashMap;

public class p146 {
    public class LRUCache {
        private int capacity;
        private LinkedHashMap<Integer, Integer> lhm;

        public LRUCache(int capacity) {
            this.capacity = capacity;
            lhm = new LinkedHashMap<>(this.capacity, 1);
        }

        public int get(int key) {
            int result = lhm.getOrDefault(key, -1);
            if (lhm.containsKey(key)) {
                lhm.remove(key);
                lhm.put(key, result);
            }
            return result;
        }

        public void put(int key, int value) {
            if (lhm.containsKey(key)) {
                lhm.remove(key);
            } else if (lhm.size() == this.capacity) {
                lhm.remove(lhm.keySet().iterator().next());
            }
            lhm.put(key, value);
        }
    }
}
