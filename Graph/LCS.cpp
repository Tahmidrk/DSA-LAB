#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char X[100], Y[100];
    cout << "Enter first string: ";
    cin >> X;
    cout << "Enter second string: ";
    cin >> Y;

    int m = strlen(X);
    int n = strlen(Y);
    int c[101][101]; // LCS length table
    char b[101][101]; // Direction table: 'D'=Diagonal, 'U'=Up, 'L'=Left

    // Initialization
    for(int i = 0; i <= m; i++)
        c[i][0] = 0;
    for(int j = 0; j <= n; j++)
        c[0][j] = 0;

    // Filling tables
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(X[i-1] == Y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 'D';
            }
            else if(c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                b[i][j] = 'U';
            }
            else {
                c[i][j] = c[i][j-1];
                b[i][j] = 'L';
            }
        }
    }

    // Print LCS length table
    cout << "\nLCS Length Table (c):\n";
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }

    // Print Direction Table
    cout << "\nDirection Table (b):\n";
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }

    // Recovering the LCS
    char lcs[101];
    int index = c[m][n];
    lcs[index] = '\0';
    int i = m, j = n;
    while(i > 0 && j > 0) {
        if(b[i][j] == 'D') {
            lcs[--index] = X[i-1];
            i--; j--;
        }
        else if(b[i][j] == 'U') {
            i--;
        }
        else {
            j--;
        }
    }

    cout << "\nLength of LCS: " << c[m][n] << endl;
    cout << "LCS: " << lcs << endl;

    return 0;
}
