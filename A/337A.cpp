#include<iostream>
#include<algorithm>
#include<limits>
using namespace std;

int main()
{
    int n, m, differ = numeric_limits<int>::max();
    cin>>n>>m;
    int arr[m];
    for(int i = 0; i < m; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr + m);
    for(int i = 0; i <= m - n; i++)
        if(differ > arr[n + i -1] - arr[i])
            differ = arr[n + i- 1] - arr[i];
    cout<<differ;
}
