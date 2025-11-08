#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int deterministicPartition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot)
            swap(arr[++i], arr[j]);
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortDeterministic(int arr[], int low, int high) {
    if (low < high) {
        int pi = deterministicPartition(arr, low, high);
        quickSortDeterministic(arr, low, pi - 1);
        quickSortDeterministic(arr, pi + 1, high);
    }
}

int randomizedPartition(int arr[], int low, int high) {
    int randomPivot = low + rand() % (high - low + 1);
    swap(arr[randomPivot], arr[high]);
    return deterministicPartition(arr, low, high);
}

void quickSortRandomized(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);
        quickSortRandomized(arr, low, pi - 1);
        quickSortRandomized(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    srand(time(0));
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr1[n], arr2[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }

    quickSortDeterministic(arr1, 0, n - 1);
    cout << "\nSorted Array (Deterministic): ";
    printArray(arr1, n);

    quickSortRandomized(arr2, 0, n - 1);
    cout << "\nSorted Array (Randomized): ";
    printArray(arr2, n);

    return 0;
}
