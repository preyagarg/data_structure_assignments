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

    int countDistinct() {
        int distinct = 0;
        for (int i = 0; i < n; i++) {
            bool isDistinct = true;
            for (int j = 0; j < i; j++) {
                if (arr[i] == arr[j]) {
                    isDistinct = false;
                    break;
                }
            }
            if (isDistinct) {
                distinct++;
            }
        }
        return distinct;
    }
};

int main() {
    Array a;
    a.read();
    cout << "Total number of distinct elements = " << a.countDistinct() << endl;
    return 0;
}
