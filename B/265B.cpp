#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n], ans = 0;
    cin>>arr[0];
    ans += arr[0] + 1;
    for(int i = 1; i < n; i++)
    {
        cin>>arr[i];
        ans += abs(arr[i] - arr[i-1]) + 2;
    }
    cout<<ans;
}

