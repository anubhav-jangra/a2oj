#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    short n;
    long long int l;
    cin>>n>>l;
    double arr[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr + n);
    double max = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(max < (arr[i] - arr[i-1])/2)
            max = (arr[i] - arr[i-1])/2;
    }
    if(max < l - arr[n-1])
        max = l - arr[n-1];
    cout<<fixed<<setprecision(10)<<max;
}
