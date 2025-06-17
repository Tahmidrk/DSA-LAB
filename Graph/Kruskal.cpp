#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int src;
    int dest;
    int weight;
    
    Edge() {}
    Edge(int src, int dest, int weight) {
        this->src = src;
        this->dest = dest;
        this->weight = weight;
    }
    
    // Comparator for sorting edges by weight
    bool operator<(const Edge& other) const {
        return this->weight < other.weight;
    }
};

class Kruskal {
private:
    static const int MAX_EDGES = 50;
    static const int MAX_VERTICES = 10;
    
    Edge edges[MAX_EDGES];
    int edgeCount;
    int parent[MAX_VERTICES];
    
public:
    Kruskal() {
        edgeCount = 0;
    }
    
    void addEdge(int src, int dest, int weight) {
        if (edgeCount < MAX_EDGES) {
            edges[edgeCount] = Edge(src, dest, weight);
            edgeCount++;
        }
    }
    
    void createGraph() {
        // Same graph as Prim's algorithm
        addEdge(0, 1, 10);
        addEdge(0, 2, 6);
        addEdge(0, 3, 5);
        
        addEdge(1, 3, 15);
        addEdge(1, 4, 8);
        
        addEdge(2, 3, 4);
        addEdge(2, 6, 6);
        
        addEdge(4, 6, 3);
        
        addEdge(5, 6, 4);
        addEdge(5, 7, 7);
        addEdge(5, 8, 6);
        
        addEdge(6, 7, 2);  // Additional edge for connectivity
        addEdge(7, 8, 1);  // Additional edge for connectivity
    }
    
    int find(int v) {
        if (parent[v] != v) {
            parent[v] = find(parent[v]);
        }
        return parent[v];
    }
    
    void unionSets(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        parent[rootB] = rootA;
    }
    
    void kruskalAlgo(int V) {
        // Sort edges by weight
        sort(edges, edges + edgeCount);
        
        // Initialize parent array for Union-Find
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }
        
        int mstCost = 0;
        int edgesUsed = 0;
        
        cout << "Edge\tWeight" << endl;
        
        for (int i = 0; i < edgeCount && edgesUsed < V - 1; i++) {
            Edge e = edges[i];
            
            if (find(e.src) != find(e.dest)) {
                unionSets(e.src, e.dest);
                cout << e.src << " - " << e.dest << "\t" << e.weight << endl;
                mstCost += e.weight;
                edgesUsed++;
            }
        }
        
        cout << "Total Weight of MST: " << mstCost << endl;
    }
};

int main() {
    int V = 9;
    Kruskal kruskal;
    kruskal.createGraph();
    kruskal.kruskalAlgo(V);
    
    return 0;
}
