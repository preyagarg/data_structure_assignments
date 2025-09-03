#include <bits/stdc++.h>
using namespace std;

void shift_replace(vector<int>&arr,int pos){
    for(int i = arr.size()-1;i>pos;i--){
        arr[i] = arr[i-1];
    }
}

void duplicateZeros(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            if(arr[i] == 0){
                shift_replace(arr,i);
                i++;
            }
        }
    }

int main(){

    vector<int> arr = {1,0,2,3,0,4,5,0};
    duplicateZeros(arr);
    for( int i:arr){
        cout<<i<<" ";
    }

}
