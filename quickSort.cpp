#include <iostream>
using namespace std;

int partition(int arr[], int first, int last) {
    int pivot = arr[last];
    int i = first - 1;

    for (int j = first; j < last; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[last]);
    return i + 1;
}

void quickSort(int arr[], int first, int last) {
    if (first >= last)
        return;

    int pi = partition(arr, first, last);
    quickSort(arr, first, pi - 1);
    quickSort(arr, pi + 1, last);
}

int main() {
    int arr[] = {20, 12, 35, 16, 18, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
    return 0;
}
// #include <iostream>
// #include <cstdlib>  // for rand() and srand()
// #include <ctime>    // for time()

// using namespace std;

// int partition(int arr[], int first, int last) {
//     // Pick a random pivot index between first and last
//     int randomIndex = first + rand() % (last - first + 1);
    
//     // Swap the randomly chosen pivot with the last element
//     swap(arr[randomIndex], arr[last]);
    
//     int pivot = arr[last];
//     int i = first - 1;

//     for (int j = first; j < last; j++) {
//         if (arr[j] < pivot) {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }

//     swap(arr[i + 1], arr[last]);
//     return i + 1;
// }

// void quickSort(int arr[], int first, int last) {
//     if (first >= last)
//         return;

//     int pi = partition(arr, first, last);
//     quickSort(arr, first, pi - 1);
//     quickSort(arr, pi + 1, last);
// }

// int main() {
//     srand(time(0));  // Seed the random number generator

//     int arr[] = {20, 12, 35, 16, 18, 30};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     quickSort(arr, 0, n - 1);

//     for (int i = 0; i < n; i++)
//         cout << arr[i] << " ";

//     cout << endl;
//     return 0;
// }
