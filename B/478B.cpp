#include<iostream>
using namespace std;

#define K (n/m)
#define R (n%m)

int main()
{
    unsigned long long int n, m;
    cin>>n>>m;
    cout<<((R* ((K+1)*K/2) ) + (m-R) * (K*(K-1)/2))<<" "<<((n - m + 1) * (n - m)) / 2;
}
