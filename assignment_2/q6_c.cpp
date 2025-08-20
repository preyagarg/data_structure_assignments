#include <iostream>
using namespace std;

class SparseMatrix {
    int row, col, val;
    int **triplet;

public:
    SparseMatrix(int r, int c, int v) {
        row = r; col = c; val = v;
        triplet = new int*[val+1];
        for (int i = 0; i <= val; i++)
            triplet[i] = new int[3];
    }

    void read() {
        triplet[0][0] = row;
        triplet[0][1] = col;
        triplet[0][2] = val;
        cout << "Enter row col value (for " << val << " non-zero elements):\n";
        for (int i = 1; i <= val; i++)
            cin >> triplet[i][0] >> triplet[i][1] >> triplet[i][2];
    }

    void display() {
        cout << "Row Col Value\n";
        for (int i = 0; i <= val; i++)
            cout << triplet[i][0] << " " << triplet[i][1] << " " << triplet[i][2] << endl;
    }

    SparseMatrix multiply(SparseMatrix s2) {
        if (col != s2.row) {
            cout << "Multiplication not possible!\n";
            return SparseMatrix(0, 0, 0);
        }

        int temp[100][100] = {0}; // temporary normal array

        for (int i = 1; i <= val; i++) {
            for (int j = 1; j <= s2.val; j++) {
                if (triplet[i][1] == s2.triplet[j][0]) {
                    temp[triplet[i][0]][s2.triplet[j][1]] += triplet[i][2] * s2.triplet[j][2];
                }
            }
        }

        // count non-zero values
        int count = 0;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < s2.col; j++)
                if (temp[i][j] != 0) count++;

        SparseMatrix prod(row, s2.col, count);
        prod.triplet[0][0] = row;
        prod.triplet[0][1] = s2.col;
        prod.triplet[0][2] = count;

        int k = 1;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < s2.col; j++) {
                if (temp[i][j] != 0) {
                    prod.triplet[k][0] = i;
                    prod.triplet[k][1] = j;
                    prod.triplet[k][2] = temp[i][j];
                    k++;
                }
            }
        }
        return prod;
    }
};

int main() {
    int r1, c1, v1, r2, c2, v2;
    cout << "Enter rows, cols, and non-zero values for 1st matrix: ";
    cin >> r1 >> c1 >> v1;
    SparseMatrix s1(r1, c1, v1);
    s1.read();

    cout << "Enter rows, cols, and non-zero values for 2nd matrix: ";
    cin >> r2 >> c2 >> v2;
    SparseMatrix s2(r2, c2, v2);
    s2.read();

    cout << "\nMatrix 1:\n"; s1.display();
    cout << "\nMatrix 2:\n"; s2.display();

    SparseMatrix prod = s1.multiply(s2);
    cout << "\nProduct Matrix:\n";
    prod.display();
    return 0;
}
