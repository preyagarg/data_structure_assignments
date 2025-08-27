#include <iostream>
#include <stack>
using namespace std;

bool canBeSorted(int arr[], int n) //arr[]={2,3,1} , n=3
{
    stack<int> st;  //empty stack is created st[]={}
    int expected = 1; // we expect sorted order starting from 1..n(or min to max) 

    for (int i = 0; i < n; i++)  //i=2
    {
        st.push(arr[i]);   //st[]={2,3} st[]={}  st[]={}

        // keep popping if stack top matches expected
        while (!st.empty() && st.top() == expected) //st.top =3 and expected =1 
                                                    //st.top=1 and expected =1
                                                    //st.top=2 and expected =2
                                                    //st.top=3 and expected =3
        {
            st.pop();                               //st[]={3} as 1 is popped  st[]={3} as 2 is popped   st[]={}
            expected++;                             //expected = 2
                                                    //expected =3

        }
    }

    // At the end, stack should be empty if perfectly sorted
    return st.empty();
}

int main() {
    int A1[] = {3, 1, 2};
    int A2[] = {2, 3, 1};

    int n1 = sizeof(A1) / sizeof(A1[0]);
    int n2 = sizeof(A2) / sizeof(A2[0]);

    cout << (canBeSorted(A1, n1) ? "YES" : "NO") << endl; // YES
    cout << (canBeSorted(A2, n2) ? "YES" : "NO") << endl; // NO

    return 0;
}
