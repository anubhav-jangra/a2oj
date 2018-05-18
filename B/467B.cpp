#include<iostream>
using namespace std;

int main()
{
    int n, m, k, counter = 0;
    cin>>n>>m>>k;
    int arr[m]= {};
    for(int i = 0; i <= m; i++)
        cin>>arr[i];

    for(int i = 0; i < m; i++)
    {
        int a = arr[m], x = 0;
        for(; a != 0 || arr[i] != 0; a /= 2, arr[i] /= 2)
        {
            if(!((arr[i]%2 == 1 && a%2 == 1) || (arr[i]%2 == 0 && a%2 == 0)))
                x++;
        }
        if(x <= k)
            counter++;
    }
    cout<<counter;
    return 0;
}
