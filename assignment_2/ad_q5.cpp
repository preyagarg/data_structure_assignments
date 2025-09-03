#include <iostream>

using namespace std;

class ArrayDuplicator {
private:
    int* arr;
    int size;

public:
    ArrayDuplicator(int* input, int n) : arr(input), size(n) {}

    void duplicateTwos() {
        // Count how many 2's we can duplicate without overflowing
        int countTwos = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] == 2) countTwos++;
        }

        int i = size - 1;           // Original array pointer (end)
        int j = size + countTwos - 1; // Imaginary expanded array pointer

        // Move backward and duplicate 2s
        while (i >= 0 && j >= 0) {
            if (j < size) {
                arr[j] = arr[i];
            }

            if (arr[i] == 2) {
                j--;
                if (j < size) {
                    arr[j] = 2;
                }
            }

            i--;
            j--;
        }
    }
};

int main() {
    int arr[] = {1, 2, 3, 2, 4, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    ArrayDuplicator duplicator(arr, size);
    duplicator.duplicateTwos();

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}

