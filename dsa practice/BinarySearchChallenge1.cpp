#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

bool isfeas(int mid, int arr[], int n, int k)
{
    int pos = arr[0], elements = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            pos = arr[i];
            elements++;
            if (elements == k)
            {
                return true;
            }
        }
    }
    return false;
}

int largest(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int result = -1;
    int left = 1;
    int right = arr[n - 1];
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (isfeas(mid, arr, n, k))
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return result;
}
int main()
{
    int arr[] = {1, 2, 8, 4, 9};
    int n = 5;
    int k = 3;
    cout << "Largest min Distance is:  " << largest(arr, n, k) << endl;
}