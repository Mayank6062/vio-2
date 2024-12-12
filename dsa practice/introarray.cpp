#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i = 0 ; i<n;i++){
        cin>>arr[i];
    }
    int maxNo = INT16_MIN;
    int minNo = INT16_MAX ;

    for(int i = 0 ; i <n; i++){
        if(arr[i]>maxNo){
            maxNo = arr[i]; // maxNo = max(maxNo,arr[i]);
        }
        if(arr[i]<minNo){
            minNo = arr[i]; //minNo = min(minNo,arr[i]);
        }
        }
    }
}