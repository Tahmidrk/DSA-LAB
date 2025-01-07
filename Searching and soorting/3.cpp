/*Problem: In a sorted array, find the first and/or last occurrence of a specified
target element.

Example:
Input: Array = [1, 3, 3, 3, 5, 7], Target = 3
Output: First Occurrence = 1, Last Occurrence = 3 */

#include <iostream>
using namespace std;

int findFirstOccurrence(int arr[], int size, int target) {
    int low = 0, high = size - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            result = mid;
            high = mid - 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int findLastOccurrence(int arr[], int size, int target) {
    int low = 0, high = size - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            result = mid;
            low = mid + 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    int array[] = {1, 3, 3, 3, 5, 7};
    int size = sizeof(array) / sizeof(array[0]);
    int target = 3;

    int first = findFirstOccurrence(array, size, target);
    int last = findLastOccurrence(array, size, target);

    if (first != -1) {
        cout << "First Occurrence = " << first << ", Last Occurrence = " << last << endl;
    } else {
        cout << "Target not found" << endl;
    }

    return 0;
}
