#include <iostream>
using namespace std;

class SparseMatrix {
    int row, col, val; // number of rows, cols, and non-zero values
    int **triplet;     // triplet representation

public:
    SparseMatrix(int r, int c, int v) {
        row = r; col = c; val = v;
        triplet = new int*[val+1]; // val+1 because first row stores info
        for (int i = 0; i <= val; i++)
            triplet[i] = new int[3];
    }

    void read() {
        cout << "Enter row col value (for " << val << " non-zero elements):\n";
        triplet[0][0] = row;
        triplet[0][1] = col;
        triplet[0][2] = val;
        for (int i = 1; i <= val; i++)
            cin >> triplet[i][0] >> triplet[i][1] >> triplet[i][2];
    }

    void display() {
        cout << "Row Col Value\n";
        for (int i = 0; i <= val; i++)
            cout << triplet[i][0] << " " << triplet[i][1] << " " << triplet[i][2] << endl;
    }

    void transpose() {
        SparseMatrix t(col, row, val);
        t.triplet[0][0] = col;
        t.triplet[0][1] = row;
        t.triplet[0][2] = val;

        int k = 1;
        for (int i = 0; i < col; i++) {
            for (int j = 1; j <= val; j++) {
                if (triplet[j][1] == i) {
                    t.triplet[k][0] = triplet[j][1];
                    t.triplet[k][1] = triplet[j][0];
                    t.triplet[k][2] = triplet[j][2];
                    k++;
                }
            }
        }
        cout << "\nTranspose Matrix:\n";
        t.display();
    }
};

int main() {
    int r, c, v;
    cout << "Enter rows, cols and number of non-zero values: ";
    cin >> r >> c >> v;
    SparseMatrix s(r, c, v);
    s.read();
    cout << "\nOriginal Matrix in Triplet form:\n";
    s.display();
    s.transpose();
    return 0;
}
