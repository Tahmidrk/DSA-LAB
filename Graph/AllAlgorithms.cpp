#include <iostream>
#include <algorithm>
#include <climits>
#include <string>
using namespace std;

// ========================= UTILITY FUNCTIONS =========================
void displayMenu() {
    cout << "\n============= DSA ALGORITHMS MENU =============" << endl;
    cout << "1. Merge Sort" << endl;
    cout << "2. Quick Sort" << endl;
    cout << "3. Kruskal's Algorithm (MST)" << endl;
    cout << "4. Prim's Algorithm (MST)" << endl;
    cout << "5. Department Network (Kruskal)" << endl;
    cout << "6. Matrix Chain Multiplication" << endl;
    cout << "7. Exit" << endl;
    cout << "===============================================" << endl;
    cout << "Enter your choice: ";
}

// ========================= MERGE SORT =========================
class MergeSort {
public:
    static void merge(int arr[], int left, int mid, int right) {
        int mergedSize = right - left + 1;
        int merged[1000];
        int n1 = left;
        int n2 = mid + 1;
        int x = 0;
        
        while (n1 <= mid && n2 <= right) {
            if (arr[n1] < arr[n2]) {
                merged[x++] = arr[n1++];
            } else {
                merged[x++] = arr[n2++];
            }
        }
        
        while (n1 <= mid) {
            merged[x++] = arr[n1++];
        }
        
        while (n2 <= right) {
            merged[x++] = arr[n2++];
        }
        
        for (int i = 0, j = left; i < mergedSize; i++, j++) {
            arr[j] = merged[i];
        }
    }
    
    static void mergeSort(int arr[], int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
    
    static void execute() {
        cout << "\n========== MERGE SORT ==========" << endl;
        int size;
        cout << "Enter the size of array: ";
        cin >> size;
        
        int arr[1000];
        cout << "Enter the elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
        
        cout << "Original array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        
        mergeSort(arr, 0, size - 1);
        
        cout << "Sorted array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// ========================= QUICK SORT =========================
class QuickSort {
public:
    static int partition(int arr[], int left, int right) {
        int pivot = arr[right];
        int i = left - 1;
        
        for (int j = left; j < right; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
        i++;
        int temp = arr[i];
        arr[i] = pivot;
        arr[right] = temp;
        
        return i;
    }
    
    static void quickSort(int arr[], int left, int right) {
        if (left < right) {
            int p = partition(arr, left, right);
            quickSort(arr, left, p - 1);
            quickSort(arr, p + 1, right);
        }
    }
    
    static void execute() {
        cout << "\n========== QUICK SORT ==========" << endl;
        int size;
        cout << "Enter the size of array: ";
        cin >> size;
        
        int arr[1000];
        cout << "Enter the elements: ";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
        
        cout << "Original array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        
        quickSort(arr, 0, size - 1);
        
        cout << "Sorted array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// ========================= EDGE STRUCTURE =========================
struct Edge {
    int src, dest, weight;
    
    Edge() {}
    Edge(int src, int dest, int weight) {
        this->src = src;
        this->dest = dest;
        this->weight = weight;
    }
    
    bool operator<(const Edge& other) const {
        return this->weight < other.weight;
    }
};

// ========================= KRUSKAL'S ALGORITHM =========================
class KruskalMST {
private:
    static const int MAX_EDGES = 50;
    static const int MAX_VERTICES = 10;
    
    Edge edges[MAX_EDGES];
    int edgeCount;
    int parent[MAX_VERTICES];
    
public:
    KruskalMST() {
        edgeCount = 0;
    }
    
    void addEdge(int src, int dest, int weight) {
        if (edgeCount < MAX_EDGES) {
            edges[edgeCount] = Edge(src, dest, weight);
            edgeCount++;
        }
    }
    
    void createSampleGraph() {
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
        addEdge(6, 7, 2);
        addEdge(7, 8, 1);
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
        sort(edges, edges + edgeCount);
        
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
    
    static void execute() {
        cout << "\n========== KRUSKAL'S MST ==========" << endl;
        KruskalMST kruskal;
        kruskal.createSampleGraph();
        kruskal.kruskalAlgo(9);
    }
};

// ========================= PRIM'S ALGORITHM =========================
class PrimMST {
private:
    static const int MAX_VERTICES = 10;
    static const int MAX_EDGES_PER_VERTEX = 10;
    
    Edge graph[MAX_VERTICES][MAX_EDGES_PER_VERTEX];
    int edgeCount[MAX_VERTICES];
    
public:
    PrimMST() {
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
    
    void createSampleGraph() {
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
    
    void primAlgo(int V) {
        bool vis[MAX_VERTICES];
        int parent[MAX_VERTICES];
        int key[MAX_VERTICES];
        
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
    
    static void execute() {
        cout << "\n========== PRIM'S MST ==========" << endl;
        PrimMST prim;
        prim.createSampleGraph();
        prim.primAlgo(9);
    }
};

// ========================= DEPARTMENT NETWORK =========================
class DepartmentNetwork {
private:
    static const int V = 7;
    static const int MAX_EDGES = 20;
    Edge edges[MAX_EDGES];
    int edgeCount;
    int parent[V];
    string departments[V] = {"CS", "EEE", "ME", "CE", "ARCH", "BBA", "ENG"};
    
public:
    DepartmentNetwork() {
        edgeCount = 0;
    }
    
    void addEdge(int src, int dest, int weight) {
        if (edgeCount < MAX_EDGES) {
            edges[edgeCount] = Edge(src, dest, weight);
            edgeCount++;
        }
    }
    
    void createDepartmentGraph() {
        addEdge(0, 1, 2);
        addEdge(0, 2, 3);
        addEdge(1, 2, 1);
        addEdge(2, 3, 4);
        addEdge(3, 4, 2);
        addEdge(4, 5, 5);
        addEdge(5, 6, 2);
        addEdge(2, 5, 6);
        addEdge(3, 6, 7);
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
    
    void kruskalDepartment() {
        sort(edges, edges + edgeCount);
        
        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }
        
        int mstCost = 0;
        cout << "Edge\t\tWeight" << endl;
        
        for (int i = 0; i < edgeCount; i++) {
            Edge e = edges[i];
            if (find(e.src) != find(e.dest)) {
                unionSets(e.src, e.dest);
                cout << departments[e.src] << " - " << departments[e.dest] << "\t\t" << e.weight << endl;
                mstCost += e.weight;
            }
        }
        
        cout << "Total Weight of MST: " << mstCost << endl;
    }
    
    static void execute() {
        cout << "\n========== DEPARTMENT NETWORK ==========" << endl;
        cout << "Mapping: 0:CS, 1:EEE, 2:ME, 3:CE, 4:ARCH, 5:BBA, 6:ENG" << endl;
        DepartmentNetwork dept;
        dept.createDepartmentGraph();
        dept.kruskalDepartment();
    }
};

// ========================= MATRIX CHAIN MULTIPLICATION =========================
class MatrixChainMultiplication {
private:
    static const int MAX_MATRICES = 20;
    int dp[MAX_MATRICES][MAX_MATRICES];
    int s[MAX_MATRICES][MAX_MATRICES];
    
public:
    MatrixChainMultiplication() {
        for (int i = 0; i < MAX_MATRICES; i++) {
            for (int j = 0; j < MAX_MATRICES; j++) {
                dp[i][j] = 0;
                s[i][j] = 0;
            }
        }
    }
    
    int mcmTabulation(int p[], int n) {
        int dp[MAX_MATRICES][MAX_MATRICES];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = 0;
            }
        }
        
        for (int length = 2; length < n; length++) {
            for (int i = 1; i < n - length + 1; i++) {
                int j = i + length - 1;
                dp[i][j] = INT_MAX;
                
                for (int k = i; k <= j - 1; k++) {
                    int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                    
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        s[i][j] = k;
                    }
                }
            }
        }
        
        return dp[1][n - 1];
    }
    
    void printOptimalParentheses(int i, int j) {
        if (i == j) {
            cout << "M" << i;
        } else {
            cout << "(";
            printOptimalParentheses(i, s[i][j]);
            printOptimalParentheses(s[i][j] + 1, j);
            cout << ")";
        }
    }
    
    void displayMatrices(int p[], int n) {
        cout << "Matrix dimensions:" << endl;
        for (int i = 0; i < n - 1; i++) {
            cout << "M" << (i + 1) << ": " << p[i] << " x " << p[i + 1] << endl;
        }
        cout << endl;
    }
    
    static void execute() {
        cout << "\n========== MATRIX CHAIN MULTIPLICATION ==========" << endl;
        MatrixChainMultiplication mcm;
        int n;
        
        cout << "Enter number of matrices: ";
        cin >> n;
        
        int p[20];
        
        cout << "Enter the dimensions (n+1 values):" << endl;
        cout << "For matrices A1(p0 x p1), A2(p1 x p2), ..., An(pn-1 x pn)" << endl;
        
        for (int i = 0; i <= n; i++) {
            cout << "p[" << i << "]: ";
            cin >> p[i];
        }
        
        mcm.displayMatrices(p, n + 1);
        
        int minCost = mcm.mcmTabulation(p, n + 1);
        
        cout << "Minimum number of scalar multiplications: " << minCost << endl;
        
        cout << "Optimal parenthesization: ";
        mcm.printOptimalParentheses(1, n);
        cout << endl;
    }
};

// ========================= MAIN FUNCTION =========================
int main() {
    int choice;
    
    do {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                MergeSort::execute();
                break;
            case 2:
                QuickSort::execute();
                break;
            case 3:
                KruskalMST::execute();
                break;
            case 4:
                PrimMST::execute();
                break;
            case 5:
                DepartmentNetwork::execute();
                break;
            case 6:
                MatrixChainMultiplication::execute();
                break;
            case 7:
                cout << "Exiting program. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
        
        if (choice != 7) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
        
    } while (choice != 7);
    
    return 0;
}
