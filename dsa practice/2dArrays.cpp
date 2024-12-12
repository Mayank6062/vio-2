#include <iostream>
using namespace std;
// tranpose of a matrix
//  int main(){
//      int a[3][3] = { {1,2,3}, {4,5,6} ,{7,8,9}};
//      for(int i = 0 ; i<3; i++){
//          for(int j = i ; j<3; j++){
//              int temp = a[i][j];
//              a[i][j] = a[j][i];
//              a[j][i] = temp;
//          }
//      }
//      for(int i = 0 ; i<3; i++){
//          for(int j = 0 ; j<3; j++){
//              cout<<a[i][j]<<" ";
//          }
//          cout<<endl;
//      }
//  return 0;
//  }

// multiplication of a matrix
// int main(){
//     int n1,n2,n3 ;
//     cin>>n1>>n2>>n3;
//     int m1[n1][n2];
//     int m2[n2][n3];

//     for(int i =0 ; i<n1; i++){
//         for(int j =0 ; j<n2; j++){
//             cin>>m1[i][j];
//         }
//     }
//     for(int i =0 ; i<n2; i++){
//         for(int j =0 ; j<n3; j++){
//             cin>>m2[i][j];
//         }
//     }
// }

// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }
//     const int N = 1e2 + 1;
//     bool cheak[N];
//     for (int i = 0; i < N; i++)
//     {
//         cheak[i] = false;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] >= 0)
//         {
//             cheak[arr[i]] = true;
//         }
//     }
//     int ans = -1;
//     for (int i = 1; i < N; i++)
//     {
//         if (cheak[i] == false)
//         {
//             ans = i;
//             break;
//         }
//     }
//     cout << ans << endl;
// }
