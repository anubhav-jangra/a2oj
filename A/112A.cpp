#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n, a = 0, i = -1;
    bool p = false;
    cin>>n;
    while(a <= n)
    {
        if(p == true)
        {
            p = false;
            a += 3*((int)pow(10, i));
        }
        else
        {
            p = true;
            a += 4*((int)pow(10, ++i));
        }
        if(n%a == 0)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
