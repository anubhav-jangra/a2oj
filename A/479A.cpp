#include<iostream>
using namespace std;

int main() 
{
    int a, b, c;
    cin>>a>>b>>c;
    int s = a + b + c;
    if(a + b * c > s)
        s = a + b * c;
    if((a + b) * c > s)
        s = (a + b) * c;
    if(a * b + c > s)
        s = a * b + c;
    if(a * (b + c) > s)
        s = a * (b + c);
    if(a * b * c > s)
        s = a * b * c;
    cout<<s;
}
