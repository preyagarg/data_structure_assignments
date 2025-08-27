#include <iostream>
#include <stack>
using namespace std;

class DailyTemperatures {
private:
    int n;
    int arr[100];     // input array (temperatures)
    int result[100];  // output array (days to wait)

public:
    // Constructor
    DailyTemperatures(int a[], int size) {
        n = size;
        for (int i = 0; i < n; i++) {
            arr[i] = a[i];
            result[i] = 0; // initialize with 0
        }
    }

    // Function to compute waiting days
    void compute() {
        stack<int> st; // stack will store indices  st={}

        for (int i = 0; i < n; i++) {  //i=2
            // While current temperature is greater than temperature at stack top
            while (!st.empty() && arr[i] > arr[st.top()]) {
                int prevIndex = st.top();
                st.pop();
                result[prevIndex] = i - prevIndex; // days waited  result={1,1}
            }
            st.push(i); // push current index
        }
    }

    // Display results
    void display() {
        cout << "Temperatures: ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << "\nWait Days:   ";
        for (int i = 0; i < n; i++) cout << result[i] << " ";
        cout << endl;
    }
};

// Driver code
int main() {
    int input[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int size = sizeof(input) / sizeof(input[0]);

    DailyTemperatures obj(input, size);
    obj.compute();
    obj.display();

    return 0;
}
