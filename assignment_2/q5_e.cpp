#include<iostream>
using namespace std;

class Symmetric {
    int n;
    int *A;
public:
    Symmetric(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
        for (int i = 0; i < n*(n+1)/2; i++) A[i] = 0;
    }

    void set(int i, int j, int x) {
        if (i >= j) A[(i*(i-1))/2 + (j-1)] = x;
        else A[(j*(j-1))/2 + (i-1)] = x;  // mirror
    }

    int get(int i, int j) {
        if (i >= j) return A[(i*(i-1))/2 + (j-1)];
        return A[(j*(j-1))/2 + (i-1)];
    }

    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }

    ~Symmetric() { delete[] A; }
};

int main() {
    Symmetric sm(4);

    sm.set(1,1,1);
    sm.set(2,1,2); sm.set(2,2,3);
    sm.set(3,1,4); sm.set(3,2,5); sm.set(3,3,6);
    sm.set(4,1,7); sm.set(4,2,8); sm.set(4,3,9); sm.set(4,4,10);

    sm.display();
}