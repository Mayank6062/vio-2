#include <iostream>
using namespace std;
// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     int arr[n][m];
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> arr[i][j];
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cout << arr[i][j];
//         }
//         cout << endl;
//     }
//     int x;
//     cin>>x;
//     bool flag = false;

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if(arr[i][j] == x){
//                 cout<<"element is found";
//                 flag = true;
//             }
//         }
//     }
//     if(flag){
//         return 1;
//     }
//     else{
//         return 0 ;
//     }
//     return 0;
// }

// spiral order array
int main()
{
    int n, m;
    cin >> n >> m;

    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int rowstart = 0, rowend = n - 1, colstart = 0, colend = m - 1;
    while (rowstart <= rowend && colstart <= colend)
    {
        // for row start
        for (int col = colstart; col <= colend; col++)
        {
            cout << a[rowstart][col];
        }
        rowstart++;

        // col end
        for (int row = rowstart; row < rowend; row++)
        {
            cout << a[row][colend];
        }
        colend--;

        // for row end
        for (int col = colend; col >= colstart; col--)
        {
            cout << a[rowend][col];
        }
        rowend--;

        // col start
        for (int row = rowend; row >= rowstart; row--)
        {
            cout << a[row][colstart];
        }
        colstart++;
    }
}