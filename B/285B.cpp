#include<iostream>
using namespace std;

/*
int findd(int arr[], int n, int temp)
{
    for(int i = 1; i <= n; i++)
    {
        if(arr[i] == temp)
        {
            arr[i] = -1;
            return i;
        }
    }
    return -1;
}
*/

int main()
{
    int n, s, t;
    cin>>n>>s>>t;
    int arr[n+1];
    for(int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    //if(s == t)
    //{
    //    cout<<0;
    //    return 0;
    //}
    int temp = s, counter = 0;
    while(temp != t)
    {
        temp = arr[temp];
        counter++;
        if(temp != -1)
            arr[s] = -1;
        else
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<counter;
/*    int temp = findd(arr, n, t), counter = 0;
    if(temp == t)
    {
        if(temp == s)
            cout<<0;
        else
            cout<<-1;
        return 0;
    }
    while(temp != s)
    {
//        temp = findd(arr, n, temp);
        counter++;
        if(temp == -1)
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<++counter;
*/
}
