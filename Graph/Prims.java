import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Prims {
    static class Edge {
        int src;
        int dest;
        int weight;

        public Edge(int src, int dest, int weight) {
            this.src = src;
            this.dest = dest;
            this.weight = weight;
        }
    }

    static class Pair implements Comparable<Pair> {
        int node;
        int cost;

        public Pair(int node, int cost) {
            this.node = node;
            this.cost = cost;
        }

        public int compareTo(Pair p2) {
            return this.cost - p2.cost;
        }
    }

    public static void createGraph(ArrayList<Edge> graph[]) {
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<>();
        }

        graph[0].add(new Edge(0, 1, 10));
        graph[0].add(new Edge(0, 2, 6));
        graph[0].add(new Edge(0, 3, 5));

        graph[1].add(new Edge(1, 0, 10));
        graph[1].add(new Edge(1, 3, 15));
        graph[1].add(new Edge(1, 4, 8));

        graph[2].add(new Edge(2, 0, 6));
        graph[2].add(new Edge(2, 3, 4));
        graph[2].add(new Edge(2, 6, 6));

        graph[3].add(new Edge(3, 0, 5));
        graph[3].add(new Edge(3, 1, 15));
        graph[3].add(new Edge(3, 2, 4));

        graph[4].add(new Edge(4, 1, 8));
        graph[4].add(new Edge(4, 6, 3));

        graph[5].add(new Edge(5, 6, 4));
        graph[5].add(new Edge(5, 7, 7));
        graph[5].add(new Edge(5, 8, 6));

        graph[6].add(new Edge(6, 2, 6));
        graph[6].add(new Edge(6, 4, 3));
        graph[6].add(new Edge(6, 5, 4));

        graph[7].add(new Edge(7, 5, 7));

        graph[8].add(new Edge(8, 5, 6));
    }

    public static void primsAlgo(ArrayList<Edge> graph[], int V) {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        boolean[] vis = new boolean[V];
        int[] parent = new int[V];
        int[] key = new int[V];

        Arrays.fill(key, Integer.MAX_VALUE);
        Arrays.fill(parent, -1);
        key[0] = 0;

        pq.add(new Pair(0, 0));
        int mstCost = 0;

        while (!pq.isEmpty()) {
            Pair curr = pq.remove();

            if (!vis[curr.node]) {
                vis[curr.node] = true;
                mstCost += curr.cost;

                for (Edge e : graph[curr.node]) {
                    if (!vis[e.dest] && e.weight < key[e.dest]) {
                        key[e.dest] = e.weight;
                        parent[e.dest] = curr.node;
                        pq.add(new Pair(e.dest, e.weight));
                    }
                }
            }
        }

        System.out.println("Edge\tWeight");
        for (int i = 1; i < V; i++) {
            System.out.println(parent[i] + " - " + i + "\t" + key[i]);
        }
        System.out.println("Total Weight of MST: " + mstCost);
    }

    public static void main(String[] args) {
        int V = 9;
        ArrayList<Edge>[] graph = new ArrayList[V];
        createGraph(graph);
        primsAlgo(graph, V);
    }
}
