#include <iostream>
using namespace std;

class MergeSort {
public:
    static void merge(int arr[], int left, int mid, int right) {
        int mergedSize = right - left + 1;
        int merged[1000]; // Using fixed size array instead of dynamic allocation
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
    
    static void printArray(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of array: ";
    cin >> size;
    
    int arr[1000]; // Using fixed size array instead of dynamic allocation
    cout << "Enter the elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    
    cout << "Original array: ";
    MergeSort::printArray(arr, size);
    
    MergeSort::mergeSort(arr, 0, size - 1);
    
    cout << "Sorted array: ";
    MergeSort::printArray(arr, size);
    
    return 0;
}
