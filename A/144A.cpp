#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int min, max;
    cin>>min;
    max = min;
    int x, min_i = 0 , max_i = 0;
    for(int i = 1; i < n; i++)
    {
        cin>>x;
        if(x > max)
        {
            max = x;
            max_i = i;
        }
        if(min >= x)
        {
            min = x;
            min_i = i;
        }
    }
    if(max_i > min_i)
        cout<<max_i + n -2 - min_i;
    else
        cout<<max_i + n - 1 - min_i;
}
