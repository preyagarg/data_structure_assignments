#include<iostream>
using namespace std;

int main()
{

    int rows,column;
    int i,k=0,j;
    cout << "enter number of rows and column of matrix=";
    cin >> rows >> column;

    int **a;
    a=new int *[rows];
    for(i=0;i<rows;i++)
    {
        a[i]=new int[column];
    }
    int b[rows];
    
    cout <<"enter diagnol element=";
    for(i=0;i<rows;i++)
    {
        cin >> b[i];
    }

    for(i=0;i<rows;i++)
    {
        for(j=0;j<column;j++)
        {
            if(i==j)
            {
                a[i][j]=b[k];
                k++;
            }

            else
            {
                a[i][j]=0;
            }
        }
    }

    for(i=0;i<rows;i++)
    {
        for(j=0;j<column;j++)
        {
            cout <<a[i][j] <<"  ";
        }
        cout << endl;
    }


}