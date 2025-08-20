#include<iostream>
using namespace std;

class LowerTriangular {
    int n;
    int *A;
public:
    LowerTriangular(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
        for (int i = 0; i < n*(n+1)/2; i++) A[i] = 0;
    }

    void set(int i, int j, int x) {
        if (i >= j) A[(i*(i-1))/2 + (j-1)] = x;
    }

    int get(int i, int j) {
        if (i >= j) return A[(i*(i-1))/2 + (j-1)];
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

    ~LowerTriangular() { delete[] A; }
};

int main() {
    LowerTriangular lt(4);

    lt.set(1,1,1);
    lt.set(2,1,2); lt.set(2,2,3);
    lt.set(3,1,4); lt.set(3,2,5); lt.set(3,3,6);
    lt.set(4,1,7); lt.set(4,2,8); lt.set(4,3,9); lt.set(4,4,10);

    lt.display();

}