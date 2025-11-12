#include <iostream>
using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i, bool increasing) {
    int extreme = i; // Initialize largest or smallest as root
    int left = 2 * i + 1;  // left child
    int right = 2 * i + 2; // right child

    // For increasing order (max heap)
    if (increasing) {
        if (left < n && arr[left] > arr[extreme])
            extreme = left;
        if (right < n && arr[right] > arr[extreme])
            extreme = right;
    }
    // For decreasing order (min heap)
    else {
        if (left < n && arr[left] < arr[extreme])
            extreme = left;
        if (right < n && arr[right] < arr[extreme])
            extreme = right;
    }

    // If root is not largest/smallest, swap and heapify again
    if (extreme != i) {
        swap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, increasing);
    }
}

// Main Heap Sort function
void heapSort(int arr[], int n, bool increasing = true) {
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, increasing);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Move current root to end
        heapify(arr, i, 0, increasing);
    }

    // If decreasing order, reverse the array
    if (!increasing) {
        for (int i = 0; i < n / 2; i++)
            swap(arr[i], arr[n - i - 1]);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    // Sort in increasing order
    heapSort(arr, n, true);
    cout << "Sorted in Increasing order: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    // Sort in decreasing order
    heapSort(arr, n, false);
    cout << "Sorted in Decreasing order: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    return 0;
}
