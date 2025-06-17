#include <iostream>
#include <climits>
using namespace std;

const int MAX = 101;
const int INF = INT_MAX;

// Dijkstra's algorithm using adjacency matrix and arrays
void dijkstra(int adj[MAX][MAX], int V, int S, int D, int dist[MAX], int parent[MAX]) {
    bool visited[MAX] = {false};
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[S] = 0;
    for (int count = 0; count < V - 1; count++) {
        int minDist = INF, u = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }
        if (u == -1) break;
        visited[u] = true;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && adj[u][v] && dist[u] != INF && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
                parent[v] = u;
            }
        }
    }
}

// Reconstruct path from S to D
int reconstruct_path(int S, int D, int parent[MAX], int path[MAX]) {
    int len = 0;
    int v = D;
    while (v != -1) {
        path[len++] = v;
        v = parent[v];
    }
    // Reverse path
    for (int i = 0; i < len / 2; i++) {
        int temp = path[i];
        path[i] = path[len - 1 - i];
        path[len - 1 - i] = temp;
    }
    if (path[0] != S) return 0; // No path
    return len;
}

// Matrix Chain Multiplication DP (arrays only)
int matrix_chain_order(int dims[], int k) {
    int dp[20][20] = {0};
    for (int l = 2; l <= k; ++l) {
        for (int i = 1; i <= k - l + 1; ++i) {
            int j = i + l - 1;
            dp[i][j] = INF;
            for (int m = i; m < j; ++m) {
                int cost = dp[i][m] + dp[m+1][j] + dims[i-1]*dims[m]*dims[j];
                if (cost < dp[i][j]) dp[i][j] = cost;
            }
        }
    }
    return dp[1][k];
}

int main() {
    int n, m;
    cin >> n >> m;
    int adj[MAX][MAX] = {0};
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u-1][v-1] = w; // 0-based indexing
    }
    int S, D;
    cin >> S >> D;
    S--; D--; // 0-based
    int dist[MAX], parent[MAX];
    dijkstra(adj, n, S, D, dist, parent);
    int path[MAX], path_len = reconstruct_path(S, D, parent, path);
    if (dist[D] == INF) {
        cout << "No path from node " << (S+1) << " to " << (D+1) << ".\n";
    } else {
        cout << "Minimum transmission cost from node " << (S+1) << " to " << (D+1) << " is: " << dist[D] << endl;
        cout << "Path: ";
        for (int i = 0; i < path_len; ++i) {
            cout << (path[i]+1);
            if (i + 1 < path_len) cout << " -> ";
        }
        cout << endl;
    }
    int k;
    cin >> k;
    int dims[21];
    for (int i = 0; i <= k; ++i) cin >> dims[i];
    int mcm_cost = matrix_chain_order(dims, k);
    cout << "Minimum matrix multiplication cost at destination node " << (D+1) << " is: " << mcm_cost << endl;
    return 0;
}
