/*Problem: Given a sorted array, find the smallest element that is greater than
or equal to the target value.

Example:
Input: Array = [2, 4, 6, 8, 10], Target = 5
Output: Result = 6*/

#include <iostream>
using namespace std;

int findCeil(int arr[], int size, int target) {
    int low = 0, high = size - 1, result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target) {
            result = arr[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    int array[] = {2, 4, 6, 8, 10};
    int size = sizeof(array) / sizeof(array[0]);
    int target = 5;

    int result = findCeil(array, size, target);

    if (result != -1) {
        cout << "Result = " << result << endl;
    } else {
        cout << "No element found" << endl;
    }

    return 0;
}
