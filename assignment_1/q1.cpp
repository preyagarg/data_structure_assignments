#include<iostream>
using namespace std;

class array
{
    private:
        int *a;
        int size;

    public:
        void create(int m)
        {
            size = m;
            a = new int[size + 1];
        }

        void setArray()
        {
            cout << "Enter array elements:";
            int i;
            for (i = 0; i < size; i++)
            {
                cin >> a[i];
            }
        }

        void insert(int pos, int value)
        {
            int i;
            for (i = size - 1; i >= pos - 1; i--)
            {
                a[i + 1] = a[i];
            }
            a[pos - 1] = value;

            cout << "Array elements are: ";
            for (int i = 0; i < size + 1; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }

        void deleteElement(int pos)
        {
            int i;
            for (i = pos - 1; i < size - 1; i++)
            {
                a[i] = a[i + 1];
            }

            cout << "Array elements are: ";
            for (int i = 0; i < size - 1; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }

        void LinearSearch(int value)
        {
            int i;
            for (i = 0; i < size; i++)
            {
                if (a[i] == value)
                {
                    cout << "element found at position: " << i + 1;
                    return;
                }
            }
            cout << "element not found in array:";
        }
};

int main()
{
    array arr;
    int n;
    int pos, value;
    cout << "Enter size of array: ";
    cin >> n;

    arr.create(n);
    arr.setArray();

    cout << "1.INSERT" << endl;
    cout << "2.DELETE" << endl;
    cout << "3.LINEAR_SEARCH" << endl;

    cout << "enter the key you want to execute:";
    int key;
    cin >> key;

    switch (key)
    {
        case 1:
            cout << "enter element and position at which u want to insert";
            cin >> value >> pos;
            arr.insert(pos, value);
            break;

        case 2:
            cout << "enter position you want to delete=";
            cin >> pos;
            arr.deleteElement(pos);
            break;

        case 3:
            cout << "enter the value you want to locate:";
            cin >> value;
            arr.LinearSearch(value);
            break;

        default:
            cout << "wrong key entered.";
    }
}