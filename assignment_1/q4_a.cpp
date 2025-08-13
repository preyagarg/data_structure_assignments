#include<iostream>
using namespace std;

class duplicate
{
    private:
    int *a;
    int size;

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
        int i;
        for(i=0;i<(size/2);i++)
        {
            int temp;
            temp=a[i];
            a[i]=a[size-1-i];
            a[size-1-i]=temp;
        }

        cout<<"reversed elements are=";
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