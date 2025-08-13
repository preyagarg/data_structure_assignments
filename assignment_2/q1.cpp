#include <iostream>
using namespace std;

class BinarySearch
{
private:
    int arr[100];
    int size;

public:
    void input()
    {
        cout << "Enter number of elements: ";
        cin >> size;
        cout << "Enter " << size << " elements (in any order): ";
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }
    void sortArray()
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

    void search(int key)
    {
        int low = 0, high = size - 1;
        bool found = false;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (arr[mid] == key)
            {
                cout << "Element found at position: " << mid + 1 << endl;
                found = true;
                break;
            }
            else if (arr[mid] < key)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        if (!found)
        {
            cout << "Element not found in the array." << endl;
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    BinarySearch obj;
    int key;

    obj.input();
    cout << "Sorting array before binary search...\n";
    obj.sortArray();

    cout << "Sorted array: ";
    obj.display();

    cout << "Enter element to search: ";
    cin >> key;

    obj.search(key);

    return 0;
}
