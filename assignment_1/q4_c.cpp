#include <iostream>
using namespace std;

class Matrix
{
private:
    int rows, cols;
    int **mat;

public:
    void create(int r, int c)
    {
        rows = r;
        cols = c;

        mat = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            mat[i] = new int[cols];
        }
    }

    void input()
    {
        cout << "Enter elements of the matrix:\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> mat[i][j];
            }
        }
    }


    void display()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }


    void transpose()
    {
        cout << "Transpose of the matrix:\n";
        for (int j = 0; j < cols; j++)
        {
            for (int i = 0; i < rows; i++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Matrix m;
    int r, c;

    cout << "Enter number of rows and columns: ";
    cin >> r >> c;

    m.create(r, c);
    m.input();

    cout << "\nOriginal Matrix:\n";
    m.display();

    cout << "\n";
    m.transpose();

    return 0;
}
