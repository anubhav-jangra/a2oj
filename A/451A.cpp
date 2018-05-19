#include<iostream>
using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    ( n > m ? (m % 2 == 0 ? cout<<"Malvika" : cout<<"Akshat") : (n % 2 == 0 ? cout<<"Malvika" : cout<<"Akshat") );
}
