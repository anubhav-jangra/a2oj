#include<iostream>
using namespace std;

int main()
{
    int n, curr = 1, b, m;
    long long int ans = 0;
    cin>>n;
    cin>>m;
    for(int i = 0; i < m; i++)
    {
        cin>>b;
        if(b >= curr)
            ans += (b - curr);
        else
            ans += (n - curr) + b;
        curr = b;
    }
    cout<<ans;
    return 0;
}
