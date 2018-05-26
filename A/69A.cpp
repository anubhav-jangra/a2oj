#include<iostream>
using namespace std;

int main()
{
    int n, temp;
    cin>>n;
    int a1 = 0, a2 = 0, a3 = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>temp;
        a1 += temp;
        cin>>temp;
        a2 += temp;
        cin>>temp;
        a3 += temp;
    }
    if(a1 == 0 && a2 == 0 && a3 == 0)
        cout<<"YES";
    else
        cout<<"NO";
}
