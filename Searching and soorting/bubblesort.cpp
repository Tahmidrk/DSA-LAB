#include <iostream>
using namespace std;

void bubblesort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
               
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void output(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;


    cout << "Enter size: ";
    cin >> n;

    int a[n]; 

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    cout << "Before sorting: ";
    output(a, n);

   
    bubblesort(a, n);

    
    cout << "After sorting: ";
    output(a, n);

    return 0;
}
