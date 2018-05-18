#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int i;
    short x;
    for(i = 0; i < 25; i++)
    {
        cin>>x;
        if(x == 1)
            break;
    }
    //cout<<"row"<<abs(2 - (i%5))<<endl;
    //cout<<"col"<<abs(2 - (i/5)) <<endl;

    cout<<abs(2 - (i%5)) + abs(2 - (i/5));
}
