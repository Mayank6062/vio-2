#include <iostream>
using namespace std;
// int main(){
//     char arr[100] = "Mayur";
//     int i = 0;
//     while(arr[i] != '\0'){
//         cout<<arr[i]<<endl;
//         i++;
//     }
//     return 0;
// }
// int main(){
//     char arr[100];
//     cin>>arr;
//     cout<<arr;
// }
// int main(){
//     int n;
//     cin>>n;
//     char arr[n+1];
//     cin>>arr;

//     bool cheak = 1;
//     for(int i =0; i<n; i++){
//         if(arr[i] != arr[n-1-i]){
//             cheak = 0 ;
//             break;
//         }
//     }
//     if(cheak == true){
//         cout<<"word is palindrone";
//     }
//     else{
//         cout<<"wrong";
//     }
//     return 0;
// }
// largest word in a sentences
int main()
{
    int n;
    cin >> n;
    cin.ignore();
    char arr[n + 1];
    cin.getline(arr, n);
    cin.ignore();
    int i = 0;
    int currLen = 0, maxlen = 0;
    int st = 0, maxst = 0;
    while(1)
    {
        if (arr[i] == ' ' || arr[i] == '\0')
        {
            if (currLen > maxlen)
            {
                maxlen = currLen;
                maxst = st;
            }
            currLen = 0;
            st = i+1;
        }
        else
        {
            currLen++;
        }
        if (arr[i] == '\0')
            break;
        i++;
    }
    cout << maxlen;
    for(int i = 0 ; i<maxlen; i++){
        cout<<arr[i+maxst];
    }
}