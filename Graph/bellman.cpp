#include <iostream>
#include <limits.h>

using namespace std;

const int MAX_VERTICES = 100;
const int MAX_EDGES = 1000;
const int INF = INT_MAX;

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;


    int u[MAX_EDGES], v[MAX_EDGES], w[MAX_EDGES];

    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> u[i] >> v[i] >> w[i];
    }

    int dist[MAX_VERTICES];
    int start;
    cout << "Enter starting vertex: ";
    cin >> start;


    for (int i = 0; i < V; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;


    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            if (dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]]) {
                dist[v[j]] = dist[u[j]] + w[j];
            }
        }
    }


    bool hasNegativeCycle = false;
    for (int j = 0; j < E; j++) {
        if (dist[u[j]] != INF && dist[u[j]] + w[j] < dist[v[j]]) {
            hasNegativeCycle = true;
            break;
        }
    }

    if (hasNegativeCycle) {
        cout << "Graph contains a negative-weight cycle.\n";
    } else {
        cout << "Shortest distances from vertex " << start << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "To " << i << ": ";
            if (dist[i] == INF)
                cout << "Unreachable\n";
            else
                cout << dist[i] << "\n";
        }
    }

    return 0;
}
