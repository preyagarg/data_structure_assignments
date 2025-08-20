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

    SparseMatrix add(SparseMatrix s2) {
        if (row != s2.row || col != s2.col) {
            cout << "Addition not possible!\n";
            return SparseMatrix(0, 0, 0);
        }

        int i = 1, j = 1, k = 1;
        SparseMatrix sum(row, col, val + s2.val);

        while (i <= val && j <= s2.val) {
            if (triplet[i][0] == s2.triplet[j][0] && triplet[i][1] == s2.triplet[j][1]) {
                sum.triplet[k][0] = triplet[i][0];
                sum.triplet[k][1] = triplet[i][1];
                sum.triplet[k][2] = triplet[i][2] + s2.triplet[j][2];
                i++; j++; k++;
            } else if ((triplet[i][0] < s2.triplet[j][0]) ||
                      (triplet[i][0] == s2.triplet[j][0] && triplet[i][1] < s2.triplet[j][1])) {
                sum.triplet[k][0] = triplet[i][0];
                sum.triplet[k][1] = triplet[i][1];
                sum.triplet[k][2] = triplet[i][2];
                i++; k++;
            } else {
                sum.triplet[k][0] = s2.triplet[j][0];
                sum.triplet[k][1] = s2.triplet[j][1];
                sum.triplet[k][2] = s2.triplet[j][2];
                j++; k++;
            }
        }

        while (i <= val) {
            sum.triplet[k][0] = triplet[i][0];
            sum.triplet[k][1] = triplet[i][1];
            sum.triplet[k][2] = triplet[i][2];
            i++; k++;
        }
        while (j <= s2.val) {
            sum.triplet[k][0] = s2.triplet[j][0];
            sum.triplet[k][1] = s2.triplet[j][1];
            sum.triplet[k][2] = s2.triplet[j][2];
            j++; k++;
        }

        sum.val = k-1;
        sum.triplet[0][0] = row;
        sum.triplet[0][1] = col;
        sum.triplet[0][2] = sum.val;
        return sum;
    }
};

int main() {
    int r, c, v1, v2;
    cout << "Enter rows, cols, and non-zero values for 1st matrix: ";
    cin >> r >> c >> v1;
    SparseMatrix s1(r, c, v1);
    s1.read();

    cout << "Enter non-zero values for 2nd matrix: ";
    cin >> v2;
    SparseMatrix s2(r, c, v2);
    s2.read();

    cout << "\nMatrix 1:\n";
    s1.display();
    cout << "\nMatrix 2:\n";
    s2.display();

    SparseMatrix sum = s1.add(s2);
    cout << "\nSum Matrix:\n";
    sum.display();
    return 0;
}
