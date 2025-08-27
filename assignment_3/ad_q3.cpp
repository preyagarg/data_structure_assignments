#include <iostream>
#include <stack>
using namespace std;

class NextGreaterElement {
private:
    int n;
    int arr[100];    // input array
    int result[100]; // stores NGE for each element

public:
    // Constructor
    NextGreaterElement(int a[], int size) //a[]={4, 5, 2, 25}  , n=4
    {
        n = size;
        for (int i = 0; i < n; i++) {
            arr[i] = a[i];                //arr[]={4, 5, 2, 25}
            result[i] = -1; // initialize with -1  result[]={-1,-1,-1,-1}
        }
    }

    // Function to compute NGE
    void compute() {
        stack<int> st; //st[]={3}    i=4

        for (int i = 0; i < n; i++)
        {
            
            while (!st.empty() && arr[i] > arr[st.top()]) {
                result[st.top()] = arr[i];    //result[]={5,25,25,-1}
                st.pop();
            }
            
            st.push(i);
        }
    
    }

    // Display results
    void display() {
        cout << "Array: ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << "\nNext Greater Elements: ";
        for (int i = 0; i < n; i++) cout << result[i] << " ";
        cout << endl;
    }
};

// Driver code
int main() {
    int input[] = {4, 5, 2, 25};
    int size = sizeof(input) / sizeof(input[0]);  //size=4

    NextGreaterElement obj(input, size);
    obj.compute();
    obj.display();

    return 0;
}
