#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float score;
};

void merge(Student arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Student L[100], R[100];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].id <= R[j].id) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(Student arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int partition(Student arr[], int low, int high) {
    int pivot = arr[high].id;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].id < pivot) {
            i++;
            Student temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    Student temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(Student arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    Student students[100];
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter ID, Name, Score for student " << (i+1) << ": ";
        cin >> students[i].id;
        cin.ignore();
        getline(cin, students[i].name);
        cin >> students[i].score;
    }
    cout << "Choose sorting algorithm:\n1. Merge Sort\n2. Quick Sort\nEnter choice: ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        mergeSort(students, 0, n - 1);
        cout << "\nSorted by ID (Merge Sort):\n";
    } else {
        quickSort(students, 0, n - 1);
        cout << "\nSorted by ID (Quick Sort):\n";
    }
    cout << "ID\tName\t\tScore" << endl;
    for (int i = 0; i < n; i++) {
        cout << students[i].id << "\t" << students[i].name << "\t\t" << students[i].score << endl;
    }
    return 0;
}
