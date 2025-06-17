#include <iostream>
#include <climits>
using namespace std;

class MatrixChainMultiplication {
private:
    static const int MAX_MATRICES = 20;
    int dp[MAX_MATRICES][MAX_MATRICES];
    int s[MAX_MATRICES][MAX_MATRICES]; // For storing optimal split points
    
public:
    MatrixChainMultiplication() {
        // Initialize dp array
        for (int i = 0; i < MAX_MATRICES; i++) {
            for (int j = 0; j < MAX_MATRICES; j++) {
                dp[i][j] = 0;
                s[i][j] = 0;
            }
        }
    }
    
    // Recursive approach with memoization
    int mcmRecursive(int p[], int i, int j) {
        if (i == j) {
            return 0;
        }
        
        if (dp[i][j] != 0) {
            return dp[i][j];
        }
        
        int minCost = INT_MAX;
        
        for (int k = i; k < j; k++) {
            int cost = mcmRecursive(p, i, k) + 
                      mcmRecursive(p, k + 1, j) + 
                      p[i - 1] * p[k] * p[j];
            
            if (cost < minCost) {
                minCost = cost;
            }
        }
        
        dp[i][j] = minCost;
        return minCost;
    }
    
    // Tabulation approach (Bottom-up DP)
    int mcmTabulation(int p[], int n) {
        int dp[MAX_MATRICES][MAX_MATRICES];
        
        // Initialize
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = 0;
            }
        }
        
        // Length of chain
        for (int length = 2; length < n; length++) {
            for (int i = 1; i < n - length + 1; i++) {
                int j = i + length - 1;
                dp[i][j] = INT_MAX;
                
                for (int k = i; k <= j - 1; k++) {
                    int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                    
                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                        s[i][j] = k; // Store optimal split point
                    }
                }
            }
        }
        
        return dp[1][n - 1];
    }
    
    // Print optimal parenthesization
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
    
    // Display matrix dimensions
    void displayMatrices(int p[], int n) {
        cout << "Matrix dimensions:" << endl;
        for (int i = 0; i < n - 1; i++) {
            cout << "M" << (i + 1) << ": " << p[i] << " x " << p[i + 1] << endl;
        }
        cout << endl;
    }
    
    // Print the DP table
    void printDPTable(int p[], int n) {
        cout << "\nDP Table (Minimum scalar multiplications):" << endl;
        cout << "   ";
        for (int j = 1; j < n; j++) {
            cout << "j=" << j << "\t";
        }
        cout << endl;
        
        for (int i = 1; i < n; i++) {
            cout << "i=" << i << " ";
            for (int j = 1; j < n; j++) {
                if (j >= i) {
                    if (mcmTabulation(p, n) || true) { // Ensure table is computed
                        cout << dp[i][j] << "\t";
                    }
                } else {
                    cout << "-\t";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    MatrixChainMultiplication mcm;
    int n;
    
    cout << "Matrix Chain Multiplication" << endl;
    cout << "Enter number of matrices: ";
    cin >> n;
    
    int p[20]; // Array to store dimensions
    
    cout << "Enter the dimensions (n+1 values):" << endl;
    cout << "For matrices A1(p0 x p1), A2(p1 x p2), ..., An(pn-1 x pn)" << endl;
    
    for (int i = 0; i <= n; i++) {
        cout << "p[" << i << "]: ";
        cin >> p[i];
    }
    
    mcm.displayMatrices(p, n + 1);
    
    // Using tabulation method
    int minCost = mcm.mcmTabulation(p, n + 1);
    
    cout << "Minimum number of scalar multiplications: " << minCost << endl;
    
    cout << "Optimal parenthesization: ";
    mcm.printOptimalParentheses(1, n);
    cout << endl;
    
    // Reset for recursive approach
    MatrixChainMultiplication mcmRec;
    int recursiveCost = mcmRec.mcmRecursive(p, 1, n);
    cout << "Minimum cost (using recursion): " << recursiveCost << endl;
    
    return 0;
}

/*
Example Input:
Number of matrices: 4
Dimensions: 1 2 3 4 5
This represents matrices:
M1: 1x2, M2: 2x3, M3: 3x4, M4: 4x5

Expected Output:
Minimum scalar multiplications: 38
Optimal parenthesization: ((M1M2)(M3M4))
*/
