#include <iostream>
#include <stack>
using namespace std;

class NearestSmallerElement {
private:
    int n;
    int arr[100];    // Input array
    int result[100]; // Stores nearest smaller elements

public:
    // Constructor to initialize array
    NearestSmallerElement(int a[], int size) //a[]={4, 5, 2, 10, 8}  , size=5
    {
        n = size;
        for (int i = 0; i < n; i++) {
            arr[i] = a[i];
            result[i] = -1; // initialize result with -1
        }
    }

    // Function to compute nearest smaller elements
    void compute() {
        stack <int> st; //creates a empty pile st[]={2}     i=3

        for (int i = 0; i < n; i++)
        {
            // Remove elements greater or equal to arr[i]
            while (!st.empty() && st.top() >= arr[i]) {  
                st.pop();
            }
 
            // If stack not empty, top is nearest smaller
            if (!st.empty()) 
            {
                result[i] = st.top();
            } 
            
            else 
            {
                result[i] = -1; // No smaller element   result[]={-1 , 4 , -1 ,2}
            }

            // Push current element
            st.push(arr[i]);
        }
    }

    // Display the result
    void display() {
        cout << "Array: ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << "\nNearest Smaller Elements: ";
        for (int i = 0; i < n; i++) cout << result[i] << " ";
        cout << endl;
    }
};

// Driver Code
int main() {
    int input[] = {4, 5, 2, 10, 8};
    int size = sizeof(input) / sizeof(input[0]); //20/4=5

    NearestSmallerElement obj(input, size);
    obj.compute();
    obj.display();

    return 0;
}
