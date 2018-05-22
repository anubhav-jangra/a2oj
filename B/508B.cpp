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
    long long int n;
    cin>>n;
    // 100000
    //  99999
    int arr[100000] = {}, index = -1, size = 0, value = 0;
    bool bo_ol = false;
    while(n != 0)
    {
        int digit = tell_digit(n);
        if(digit > size)
        {
            size = digit;
        }
        arr[size - digit] = n%10;
        n /= 10;
    }
    // sort(arr, arr + size, [](int x, int y){return x>y?x:y;});
    for(int i = 0; i < size; i++)
    {
        if(arr[i] % 2 == 0)
        {
            if(bo_ol && arr[i] < arr[0])
                index = i;
            if(index == -1)
            {
                index = i;
                bo_ol = true;
            }
        }
    }
    if(!bo_ol)
        cout<<"-1";
    else
    {
        swap(arr[index], arr[0]);
        for(int i = size - 1; i >= 0; i--)
        {
            cout<<arr[i];
        }
    }
}
