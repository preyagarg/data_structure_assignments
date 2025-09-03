#include <iostream>
using namespace std;

bool sol(string str){
    int arr[26] = {0};
    for (int i = 0; i < str.size(); i++)
    {
        arr[str[i] - 'a']++;
    }
    for (int i = 0; i < str.size(); i++)
    {
        if(arr[i]==3) return true;
    }
    return false;
}

int main(){

    string str = "abcabab";
    cout<<sol(str);


}
