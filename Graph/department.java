import java.util.*;
public class department {
    static class Edge implements Comparable<Edge> {
        int src,dest,weight;
        public Edge(int src,int dest,int weight){
            this.src=src;
            this.dest=dest;
            this.weight=weight;
        }
        public int compareTo(Edge e){
            return this.weight - e.weight;
        }
    }
    static int V=7;
    static List<Edge>edges=new ArrayList<>();
    static int parent[]=new int[V];
    static String[] departrments={"CS","EEE","ME","CE","ARCH","BBA","ENG"};

    static int find(int v){
        if (parent[v]!=v){
            parent[v]=find(parent[v]);
        }
        return parent[v];
    }
    static void union(int a,int b){
        int rootA=find(a);
        int rootB=find(b);
        parent[rootB]=rootA;
    }
    static void Kruskal(){
        Collections.sort(edges);
        for (int i=0;i<V;i++){
            parent[i]=i;
        }
        int mstCost=0;
        System.out.println("Edge\tWeight");
        for (Edge e:edges){
            if (find(e.src)!=find(e.dest)){
                union(e.src,e.dest);
                System.out.println(departrments[e.src]+" - "+departrments[e.dest]+"\t"+e.weight);
                mstCost+=e.weight;
            }
        }
        System.out.println("Total Weight of MST:"+mstCost);
    }
    public static void main(String[] args) {
        // Mapping: 0: CS, 1: EEE, 2: ME, 3: CE, 4: Arch, 5: BBA, 6: English

        edges.add(new Edge(0, 1, 2));
        edges.add(new Edge(0, 2, 3));
        edges.add(new Edge(1, 2, 1));
        edges.add(new Edge(2, 3, 4));
        edges.add(new Edge(3, 4, 2));
        edges.add(new Edge(4, 5, 5));
        edges.add(new Edge(5, 6, 2));
        edges.add(new Edge(2, 5, 6));
        edges.add(new Edge(3, 6, 7));

        Kruskal();
    }
}
/*Output:
Edge	Weight
EEE-ME	1
CS-EEE	2
CE-ARCH	2
BBA-ENG	2
ME-CE	  4
ARCH-BBA 5
Total Weight of MST:16

*/
