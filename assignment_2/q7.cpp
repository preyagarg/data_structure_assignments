#include <iostream>
using namespace std;

class Array {
    int arr[100], n;

public:
    void read() {
        cout << "Enter size of array: ";
        cin >> n;
        cout << "Enter " << n << " elements:\n";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
    }

    int countInversions() {
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] > arr[j]) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main() {
    Array a;
    a.read();
    cout << "Total number of inversions = " << a.countInversions() << endl;
    return 0;
}