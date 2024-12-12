#include<iostream>
//cheak number is power of 2
#include<vector>
using namespace std ;


bool ispowerof2(int n ){
    return (n & !(n&n-1));
}

int main(){
    cout<<ispowerof2(0);
}