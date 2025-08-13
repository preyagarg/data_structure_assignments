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
        cout << "Matrix:\n";
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

  
    void sumRows()
    {
        cout << "\nSum of each row:\n";
        for (int i = 0; i < rows; i++)
        {
            int sum = 0;
            for (int j = 0; j < cols; j++)
            {
                sum += mat[i][j];
            }
            cout << "Row " << i + 1 << ": " << sum << endl;
        }
    }

   
    void sumCols()
    {
        cout << "\nSum of each column:\n";
        for (int j = 0; j < cols; j++)
        {
            int sum = 0;
            for (int i = 0; i < rows; i++)
            {
                sum += mat[i][j];
            }
            cout << "Column " << j + 1 << ": " << sum << endl;
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

    cout << "\n";
    m.display();

    m.sumRows();
    m.sumCols();

    return 0;
}
