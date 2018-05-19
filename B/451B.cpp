#include<iostream>
using namespace std;

int main()
{
    int n, a, b;
    cin>>n;
    if(n == 1)
        cout<<"yes\n1 1";
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    for(int i = 1; i < n; i++)
    {
        if(i == n-1)
        {
            if(arr[i] > arr[i-1])
            {
                cout<<"yes\n1 1";
                return 0;
            }
        }
        if(arr[i] > arr[i-1])
            continue;
        if(arr[i-1] > arr[i])
        {
            a = i;
            //cout<<"a is assigned as -> "<<a<<"\n";
            break;
        }
    }
    if(a == 1 && n == 2)
    {
        int b = n;
        cout<<"yes\n"<<a<<" "<<b;
        return 0;
    }
    for(int i = a + 1; i <= n; i++)
    {
        if(i == n)
        {
            int b = n - 1;
            if(a == n - 1)
            {
                cout<<"yes\n"<<a<<" "<<n;
                return 0;
            }
            else if(a == 1)
            {
                cout<<"yes\n"<<a<<" "<<n;
                return 0;
            }
            else if(arr[b] > arr[a - 2])
            {
                cout<<"yes\n";
                cout<<a<<" "<<n;
                return 0;
            }
            else
            {
                cout<<"no";
                return 0;
            }
        }
        if(arr[i - 1] > arr[i])
            continue;
        if(arr[i] > arr[i-1])
        {
            b = i;
            //cout<<"b is assigned as -> "<<b<<"\n";
            break;
        }
    }

    for(int i = b + 1; i <= n; i++)
    {
        if(i == n)
        {
            if(arr[b] > arr[a - 1])
            {
                cout<<"yes\n";
                cout<<a<<" "<<b;
                return 0;
            }
            else
            {
                cout<<"no";
                return 0;
            }
        }
        else if(arr[i] < arr[i-1])
        {
            cout<<"no";
            return 0;
        }
    }
}
