#include<iostream>
#include<cmath>
using namespace std;

void print_modulo(__int64 n)
{
    while(n < 0)
    {
        n += (int) (pow(10, 9) + 7);
    }
    cout<<(n)%((int) (pow(10, 9) + 7))<<endl;
}

int main()
{
    __int64 x, y, n, ans;
    cin>>x>>y>>n;
    
    switch(n % 6)
    {
        case 0:
            ans = x - y;
            break;
        case 1:
            ans = x;
            break;
        case 2:
            ans = y;
            break;
        case 3:
            ans = y - x;
            break;
        case 4:
            ans = - x;
            break;
        case 5:
            ans = - y;
            break;
    }
    print_modulo(ans);
}
