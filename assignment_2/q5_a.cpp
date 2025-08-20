#include <iostream>
using namespace std;

class Diagonal {
    int n;      // size of matrix (n x n)
    int *A;     // 1D array to store diagonal elements
public:
    Diagonal(int n) {
        this->n = n;
        A = new int[n];
        for (int i = 0; i < n; i++) A[i] = 0;
    }

    void set(int i, int j, int x) {
        if (i == j) A[i - 1] = x;   // store only diagonal
    }

    int get(int i, int j) {
        if (i == j) return A[i - 1];
        return 0;
    }

    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) cout << A[i] << " ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }

    ~Diagonal() { delete[] A; }
};

int main() {
    Diagonal d(4);

    d.set(1,1,5);
    d.set(2,2,8);
    d.set(3,3,9);
    d.set(4,4,12);

    d.display();
}
