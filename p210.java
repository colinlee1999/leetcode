import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Stack;

public class p210 {
    public class Solution {
        private class Graph {
            private int V;   // No. of vertices
            private LinkedList<Integer> adj[]; // Adjacency List
            private boolean hasLoop;

            Graph(int v) {
                V = v;
                adj = new LinkedList[v];
                for (int i = 0; i < v; ++i)
                    adj[i] = new LinkedList();
            }

            void addEdge(int v, int w) {
                adj[v].add(w);
            }

            void topologicalSortUtil(int v, int visited[],
                                     Stack stack) {
                visited[v] = 1;
                Integer i;

                Iterator<Integer> it = adj[v].iterator();
                while (it.hasNext()) {
                    i = it.next();
                    if (visited[i] == 0)
                        topologicalSortUtil(i, visited, stack);
                    else if (visited[i] == 1)
                        hasLoop = true;
                }

                visited[v] = 2;
                stack.push(new Integer(v));
            }

            int[] topologicalSort() {
                Stack stack = new Stack();

                int visited[] = new int[V];
                Arrays.fill(visited, 0);
                hasLoop = false;
                for (int i = 0; i < V; i++)
                    if (visited[i] == 0)
                        topologicalSortUtil(i, visited, stack);

                int[] result = new int[V];
                int i = 0;
                while (!stack.isEmpty()) {
                    result[i] = (int) stack.pop();
                    ++i;
                }
                return result;
            }

            public boolean hasLoop() {
                return hasLoop;
            }
        }

        public int[] findOrder(int numCourses, int[][] prerequisites) {
            Graph g = new Graph(numCourses);
            for (int[] pair :
                    prerequisites) {
                g.addEdge(pair[1], pair[0]);
            }
            int[] result = g.topologicalSort();
            if (g.hasLoop) {
                return new int[0];
            } else {
                return result;
            }
        }
    }
}
