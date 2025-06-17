#include <iostream>
using namespace std;

class Quicksort {
public:
    static int partition(int arr[], int left, int right) {
        int pivot = arr[right];
        int i = left - 1;
        
        for (int j = left; j < right; j++) {
            if (arr[j] < pivot) {
                i++;
                // Swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
        i++;
        // Swap arr[i] and arr[right] (pivot)
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
    
    static void printArray(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    static void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    
    int arr[1000]; // Using fixed size array
    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    cout << "Original array: ";
    Quicksort::printArray(arr, size);
    
    Quicksort::quickSort(arr, 0, size - 1);
    
    cout << "Sorted array: ";
    Quicksort::printArray(arr, size);
    
    return 0;
}
