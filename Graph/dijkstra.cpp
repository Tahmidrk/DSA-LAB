#include <iostream>
#include <limits.h>

using namespace std;

const int MAX = 100;
const int INF = INT_MAX;

int extractMin(int dist[], bool visited[], int V) {
    int minDist = INF;
    int minIndex = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < minDist) {
            minDist = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

int main() {
    int V, E;
    int adj[MAX][MAX] = {0}; 

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
       
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    int dist[MAX];
    bool visited[MAX];


    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[start] = 0;


    for (int i = 0; i < V - 1; i++) {
        int u = extractMin(dist, visited, V);
        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && adj[u][v] && dist[u] != INF
                && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

 
    cout << "Shortest distances from vertex " << start << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "To " << i << ": ";
        if (dist[i] == INF)
            cout << "Unreachable\n";
        else
            cout << dist[i] << "\n";
    }

    return 0;
}
