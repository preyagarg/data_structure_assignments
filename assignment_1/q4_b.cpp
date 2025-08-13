#include <iostream>
using namespace std;

class duplicate
{
private:
    int **a;
    int **b;
    int **c;
    int rows1, columns1;
    int rows2, columns2;

public:
    void create_array1(int r, int c)
    {
        rows1 = r;
        columns1 = c;
        a = new int *[rows1];
        for (int i = 0; i < rows1; i++)
        {
            a[i] = new int[columns1];
        }
    }

    void create_array2(int r, int c)
    {
        rows2 = r;
        columns2 = c;
        b = new int *[rows2];
        for (int i = 0; i < rows2; i++)
        {
            b[i] = new int[columns2];
        }
    }

    void create_array3()
    {
        c = new int *[rows1];
        for (int i = 0; i < rows1; i++)
        {
            c[i] = new int[columns2];
        }
    }

    void initialise_array()
    {
        cout << "Enter 1st array elements:\n";
        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < columns1; j++)
            {
                cin >> a[i][j];
            }
        }

        cout << "Enter 2nd array elements:\n";
        for (int i = 0; i < rows2; i++)
        {
            for (int j = 0; j < columns2; j++)
            {
                cin >> b[i][j];
            }
        }
    }

    void matrix_multiplication()
    {
        if (columns1 != rows2)
        {
            cout << "Multiplication not possible\n";
            return;
        }

        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < columns2; j++)
            {
                c[i][j] = 0;
                for (int k = 0; k < columns1; k++)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }

        cout << "Multiplied matrix is:\n";
        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < columns2; j++)
            {
                cout << c[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    duplicate obj;
    int r1, c1, r2, c2;

    cout << "Enter rows and columns of 1st array: ";
    cin >> r1 >> c1;

    cout << "Enter rows and columns of 2nd array: ";
    cin >> r2 >> c2;

    obj.create_array1(r1, c1);
    obj.create_array2(r2, c2);
    obj.create_array3();
    obj.initialise_array();
    obj.matrix_multiplication();

    return 0;
}