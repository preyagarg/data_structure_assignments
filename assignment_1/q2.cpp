#include<iostream>
using namespace std;

class duplicate
{
    private:
    int *a;
    int size;
    int maximum;
    int *h;

    public:
    
    void create_array(int m)
    {
        size=m;
        a=new int[size];
    }

    void initialise_array()
    {
        int i;
        cout << "enter array elements=";
        for(i=0;i<size;i++)
        {
            cin>>a[i];
        }
    }


    void remove_duplicate()
    {
        int i,j,k;
        for(i=0;i<size-1;i++)
        {
            for(j=i+1;j<size;j++)
            {
                if(a[i]==a[j])
                {
                    for(k=j;k<size;k++)
                    {
                        a[k]=a[k+1];
                        size--;
                    }
                }
            }

        }

        cout<<"unique element are=";
        for(i=0;i<size;i++)
        {
            cout << a[i]<<" ";
        }

    }




};

int main()
{
    duplicate a;
    cout << "enter size of array you want=";
    int m;
    cin >> m;

    a.create_array(m);
    a.initialise_array();
    a.remove_duplicate();

    return 0;
}