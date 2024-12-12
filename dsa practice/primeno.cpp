#include<iostream>
// #include<cmath>
#include<math.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    bool flag = 0;
    for(int i = 2 ; i<=sqrt(n); i++){
        if(n%i==0){
            cout<<"non-prime";
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        cout<<"prime";
    }
}

reverse a number 
int main(){
    int n;
    cin>>n;
    int reverse = 0;
    while(n>0){
        int lastdigit = n%10;
        reverse = reverse *10 + lastdigit;
        n = n/10;
    }
    cout<<reverse<<endl;
}

armstrong number
int main(){
    int n ;
    cin>>n;
    int sum=0 ;
    int original = n ;
    while(n>0){
        int lastdigit = n%10;
        sum+= pow(lastdigit,3);
        n = n/10;
    }

    if(sum==original){
        cout<<"armstong number"<<endl;
    }
    else{
        cout<<"not";
    }
    return 0 ;
    
}