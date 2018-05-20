#include<iostream>
#include<algorithm>
using namespace std;

int tell_digit(int n)
{
    int i = 0;
    while(n != 0)
    {
        n /= 10;
        ++i;
    }
    return i;
}

int main()
{
    cout<<"7/1 = "<<7/1<<endl;
    int n;
    cin>>n;
    // 100000
    //  99999
    int arr[5] = {}, index, size = 0;
    bool bo_ol = false;
    for(int i = 10000; i >= 1; i = i/10)
    {
        int digit = tell_digit(i);
        if(n % i)
        {
            if(digit > size)
                size = digit;
            arr[digit - 1] = n/i;
            n %= i;
            if(!(arr[digit] % 2) && bo_ol)
            {
                bo_ol = true;
                index = digit;
            }
        }
        cout<<"n is -> "<<n<<"--------"<<"i is - "<<i<<"////"<<digit - 1<<" (digit - 1)'s value is - "<<arr[digit - 1]<<"\n";
    }
    if(!bo_ol)
        cout<<"-1";
    else
    {
        swap(arr[index], arr[0]);
        for(int i = size; i >= 0; i++)
        {
            cout<<arr[i];
        }
    }
}
