#include <iostream>
#include <climits>
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
};

class Prims {
private:
    static const int MAX_VERTICES = 10;
    static const int MAX_EDGES_PER_VERTEX = 10;
    
    Edge graph[MAX_VERTICES][MAX_EDGES_PER_VERTEX];
    int edgeCount[MAX_VERTICES];
    
public:
    Prims() {
        for (int i = 0; i < MAX_VERTICES; i++) {
            edgeCount[i] = 0;
        }
    }
    
    void addEdge(int src, int dest, int weight) {
        if (edgeCount[src] < MAX_EDGES_PER_VERTEX) {
            graph[src][edgeCount[src]] = Edge(src, dest, weight);
            edgeCount[src]++;
        }
    }
    
    void createGraph() {
        addEdge(0, 1, 10);
        addEdge(0, 2, 6);
        addEdge(0, 3, 5);
        
        addEdge(1, 0, 10);
        addEdge(1, 3, 15);
        addEdge(1, 4, 8);
        
        addEdge(2, 0, 6);
        addEdge(2, 3, 4);
        addEdge(2, 6, 6);
        
        addEdge(3, 0, 5);
        addEdge(3, 1, 15);
        addEdge(3, 2, 4);
        
        addEdge(4, 1, 8);
        addEdge(4, 6, 3);
        
        addEdge(5, 6, 4);
        addEdge(5, 7, 7);
        addEdge(5, 8, 6);
        
        addEdge(6, 2, 6);
        addEdge(6, 4, 3);
        addEdge(6, 5, 4);
        
        addEdge(7, 5, 7);
        
        addEdge(8, 5, 6);
    }
    
    int findMinKey(int key[], bool vis[], int V) {
        int min = INT_MAX;
        int minIndex = -1;
        
        for (int v = 0; v < V; v++) {
            if (!vis[v] && key[v] < min) {
                min = key[v];
                minIndex = v;
            }
        }
        return minIndex;
    }
    
    void primsAlgo(int V) {
        bool vis[MAX_VERTICES];
        int parent[MAX_VERTICES];
        int key[MAX_VERTICES];
        
        // Initialize arrays
        for (int i = 0; i < V; i++) {
            vis[i] = false;
            parent[i] = -1;
            key[i] = INT_MAX;
        }
        
        key[0] = 0;
        int mstCost = 0;
        
        for (int count = 0; count < V; count++) {
            int u = findMinKey(key, vis, V);
            
            if (u == -1) break;
            
            vis[u] = true;
            mstCost += key[u];
            
            // Update key values of adjacent vertices
            for (int i = 0; i < edgeCount[u]; i++) {
                Edge e = graph[u][i];
                int v = e.dest;
                
                if (!vis[v] && e.weight < key[v]) {
                    key[v] = e.weight;
                    parent[v] = u;
                }
            }
        }
        
        cout << "Edge\tWeight" << endl;
        for (int i = 1; i < V; i++) {
            if (parent[i] != -1) {
                cout << parent[i] << " - " << i << "\t" << key[i] << endl;
            }
        }
        cout << "Total Weight of MST: " << mstCost << endl;
    }
};

int main() {
    int V = 9;
    Prims prim;
    prim.createGraph();
    prim.primsAlgo(V);
    
    return 0;
}
