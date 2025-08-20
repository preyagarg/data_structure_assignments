#include <iostream>
using namespace std;

class MissingNumber {
    int arr[100], n; // n-1 elements

public:
    void read() {
        cout << "Enter n (range 1 to n): ";
        cin >> n;
        cout << "Enter " << n-1 << " sorted elements:\n";
        for (int i = 0; i < n-1; i++) {
            cin >> arr[i];
        }
    }

    // (a) Linear time approach
    int findLinear() {
        for (int i = 0; i < n-1; i++) {
            if (arr[i] != i+1) {
                return i+1;
            }
        }
        return n; // if last number is missing
    }

    // (b) Binary search approach
    int findBinary() {
        int low = 0, high = n-2;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == mid+1) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low+1;
    }
};

int main() {
    MissingNumber obj;
    obj.read();

    cout << "Missing Number (Linear) = " << obj.findLinear() << endl;
    cout << "Missing Number (Binary Search) = " << obj.findBinary() << endl;

    return 0;
}
