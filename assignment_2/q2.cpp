#include <iostream>
using namespace std;

class BubbleSort
{
private:
    int arr[7] = {64, 34, 25, 12, 22, 11, 90};
    int size = 7;

public:
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void sort()
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
};

int main()
{
    BubbleSort b;

    cout << "Original array: ";
    b.display();

    b.sort();

    cout << "Sorted array:   ";
    b.display();

    return 0;
}
