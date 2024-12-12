#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// int sum(int n ){
//     int ans = 0;
//     for(int i = 0 ; i<=n; i++){
//         ans += i;
//     }
//     return ans;
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<sum(n);

// bool cheak(int x, int y, int z)
// {
//     int a = max(x, max(y, z));
//     int b, c;
//     if (a == x)
//     {
//         b = y;
//         c = z;
//     }
//     else if (a == y)
//     {
//         b = x;
//         c = z;
//     }
//     else
//     {
//         b = x;
//         c = y;
//     }
//     if (a * a == b * b + c * c)
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
// int main()
// {
//     int x, y, z;
//     cin >> x>> y>> z;

//     if (cheak(x, y, z))
//     {
//         cout << "pythagorean triplet";
//     }
//     else
//     {
//         cout << "wrong";
//     }
// }
// int binarytodecimal(int n){
//     int ans = 0;
//     int x = 1;
//     while(n>0){
//         int y = n%10;
//         ans += x*y;
//         x*=2;
//         n= n/10;
//     }
//     return ans;
// }
// int main(){
//     int n;
//     cin>>n;

//     cout<<binarytodecimal(n);
//     return 0;
// }
// int octalTodecimal(int n){
//     int ans = 0;
//     int x = 1;
//     while(n>0){
//         int y = n%10;
//         ans += x*y;
//         x*=8;
//         n= n/10;
//     }
//     return ans;
// }
// int main(){
//     int n;
//     cin>>n;

//     cout<<octalTodecimal(n);
//     return 0;
// }
// int hexadecimaltodecimsl(string n){
//     int ans = 0;
//     int x = 1;
//     int s =n.size();
//     for(int i = s-1;i>=0; i--){
//         if(n[i]>= '0' && n[i]<='9'){
//             ans += x*(n[i]-'0');
//         }
//         else if(n[i] >= 'A' && n[i] <= 'F'){
//             ans += x*(n[i]-'A'+10);
//         }
//         x*=16 ;
//     }
//     return ans ;
// }
// int main(){
//     string n;
//     cin>>n;
//     cout<<hexadecimaltodecimsl(n);
// }
// int  decimaltobinary(int n){
//     int x =1;
//     int ans = 0;
//     while(x<=n){
//         x*=2;
//     }
//     x/=2;
//     while(x>0){
//         int lastdigit = n/x;
//         n-= lastdigit*x;
//         x/=2;
//         ans = ans*10 +lastdigit;
//     }
//     return ans;
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<decimaltobinary(n);
// }
// int  decimaltooctal(int n){
//     int x =1;
//     int ans = 0;
//     while(x<=n){
//         x*=8;
//     }
//     x/=8;
//     while(x>0){
//         int lastdigit = n/x;
//         n-= lastdigit*x;
//         x/=8;
//         ans = ans*10 +lastdigit;
//     }
//     return ans;
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<decimaltooctal(n);
// }
// string decimaltohexadecimal(int n){
//     int x = 1;
//     string ans = "";
//     while(x <= n) {
//         x*=16;
//     }
//     x /= 16;
//     while(x>0){
//         int lastdigit = n/x;
//         n-= lastdigit *x;
//         x /=16;
//     }
//     if(lastdigit <=9){
//         ans = ans + to_string(lastdigit);

//     }
//     else{
//         char c = 'A'+lastdigit -10;
//         ans.push_back(c);
//     }
//     return ans;
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<decimaltohexadecimal(n);
// }
//add two binary number
int reverse(int n)
{
    int ans = 0;
    while (n > 0)
    {
        int lastdigit = n % 10;
        ans = ans * 10 + lastdigit;
        n /= 10;
    }
    return ans;
}
int addbinary(int a, int b)
{
    int ans = 0;
    int prevcarry = 0;
    while (a > 0 && b > 0)
    {
        if (a % 2 == 0 && b % 2 == 0)
        {
            ans = ans * 10 + prevcarry;
            prevcarry = 0;
        }
        else if ((a % 2 == 0 && b % 2 == 1) || (a % 2 == 1 && b % 2 == 0))
        {
            if (prevcarry == 1)
            {
                ans = ans * 10 + 1;
                prevcarry = 1;
            }
            else
            {
                ans = ans * 10 + 0;
                prevcarry = 0;
            }
        }
        else
        {
            ans = ans * 10 + prevcarry;
            prevcarry = 1;
        }
        a /= 10;
        b /= 10;
    }
    while (a > 0)
    {
        if (prevcarry == 1)
        {
            if (a % 2 == 1)
            {
                ans = ans * 10 + 0;
                prevcarry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                prevcarry = 0;
            }
        }
        else
        {
            ans = ans * 10 + (a % 2);
        }
        a /= 10;
    }
    while (b > 0)
    {
        if (prevcarry == 1)
        {
            if (b % 2 == 1)
            {
                ans = ans * 10 + 0;
                prevcarry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                prevcarry = 0;
            }
        }
        else
        {
            ans = ans * 10 + (b % 2);
        }
        b /= 10;
    }
    if (prevcarry == 1)
    {
        ans = ans * 10 + 1;
    }
    ans = reverse(ans);
    return ans;
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << addbinary(a, b);
}