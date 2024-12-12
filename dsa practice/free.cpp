
using namespace std;
int main()
{
    
    cin  n;
    int arr[n];
    int maxsum = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int currsum[n + 1];
    currsum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        currsum[i] = currsum[i - 1] + arr[i - 1];
    }
    for (int i = 1; i <=n; i++)
    {
        int sum = 0;
        for (int j = 0; j < i; j++)
        {
            sum = currsum[i] - currsum[j];
            maxsum = max(sum, maxsum);
        }
    } 
    cout << maxsum << " ";
}
