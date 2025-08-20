#include<iostream>
using namespace std;

class UpperTriangular {
    int n;
    int *A;
public:
    UpperTriangular(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
        for (int i = 0; i < n*(n+1)/2; i++) A[i] = 0;
    }

    void set(int i, int j, int x) {
        if (i <= j) A[(i-1)*n - (i-2)*(i-1)/2 + (j-i)] = x;
    }

    int get(int i, int j) {
        if (i <= j) return A[(i-1)*n - (i-2)*(i-1)/2 + (j-i)];
        return 0;
    }

    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }

    ~UpperTriangular() { delete[] A; }
};

int main() {
    UpperTriangular ut(4);

    ut.set(1,1,1); ut.set(1,2,2); ut.set(1,3,3); ut.set(1,4,4);
    ut.set(2,2,5); ut.set(2,3,6); ut.set(2,4,7);
    ut.set(3,3,8); ut.set(3,4,9);
    ut.set(4,4,10);

    ut.display();
}