#include<iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b != 0)
       return gcd(b, a%b);
    else 
       return a;
}

bool not_done(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > 1)
            return true;
    }
    return false;
}

bool all_same(int arr[], int n)
{
    int a = arr[0];
    if(a == 1)
        return false;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] != a)
            return false;
    }
    return true;
}

int main()
{
    int n, p = 0, q = 0;
    cin>>n;
    //cout<<gcd(2,2)<<gcd(3,2)<<gcd(1, 4);
    int arr[n], counter = 0;
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    while(not_done(arr, n))
    {
        //cout<<"not_done(arr, n) ->"<<not_done(arr, n)<<endl;
        for(int i = 0; i < n-1 && not_done(arr, n); i++)
        {
            cout<<"array is -> ";
            for(int i = 0; i < n; i++)
                cout<<arr[i]<<" ";
            cout<<endl<<"i is ->"<<i<<endl;
            if(!(arr[i] == 1 && arr[i+1] == 1))
            {
                if(gcd(arr[i], arr[i + 1]) == 1)
                {
                    cout<<"changed\n";
                    if(arr[i] != 1)
                        arr[i] = 1;
                    else if(arr[i+1] != 1)
                        arr[i+1] = 1;
                    else
                        counter--;
                    counter++;
                }
                else if(p = q + 1 )
                {
                    cout<<"changed";
                    if(arr[i] != gcd(arr[i], arr[i+1]))
                        arr[i] = gcd(arr[i], arr[i+1]);
                    else if(arr[i+1] != gcd(arr[i], arr[i+1]))
                        arr[i + 1] = gcd(arr[i], arr[i+1]);
                    else
                    {
                        q--;
                        counter--;
                    }
                    counter++;
                    q++;
                }
            }
        }
        p++;
        if(all_same(arr, n))
        {
            cout<<"-1";
            return 0;
        }
    }
    cout<<counter;
}
