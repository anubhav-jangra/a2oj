#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

void swapp(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findMedian(int arr[], int n) {
    sort(arr, arr+n);
    return arr[n/2];
}

// partitions the array[l, r] around x
int partition(int arr[], int l, int r, int x) {
    // Search for the element x and swap it to end
    int i;
    for(i = l; i < r; i++)
        if(arr[i] == x)
            break;
    swapp(&arr[i], &arr[r]);

    // Standard partition program
    i = l;
    for(int j = l; j < r; j++) {
        if(arr[j] <= x) {
            swapp(&arr[i], &arr[j]);
            i++;
        }
    }
    swapp(&arr[i], &arr[r]);
    return i;
}

// returns kth smallest element from arr[l, r]
int kthSmallest(int arr[], int l, int r, int k) {
    // if k is smaller than the size of range given
    if(k > 0 && k <= r - l + 1) {
        int n = r - l + 1;
        int i, median[(n+4)/5];         // there will be floor((n+4)/5) groups of 5 in given range
        for(i = 0; i < n/5; i++)
            median[i] = findMedian(arr + l + i*5, 5);
        // for last group with less than 5 elements
        if(i*5 < n) {
            median[i] = findMedian(arr + l + i*5, n%5);
            i++;
        }
        // find median of medians using recursive call
        // If median[] has only one element, then no need of recursive call
        int medOfMed = (i == 1) ? median[i-1] : kthSmallest(median, 0, i-1, i/2);

        int pos = partition(arr, l, r, medOfMed);

        if(pos-l == k-1)
            return arr[pos];
        if(pos-l > k-1)
            return kthSmallest(arr, l, pos-1, k);
        return kthSmallest(arr, pos+1, r, k-pos+l-1);
    }
    // if k is not in apt range
    return numeric_limits<int>::max();
}

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
    int arr[n], counter = 0;
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    int least = kthSmallest(arr, 0, n-1, 1);
    // cout<<"least number is -> "<<least<<endl;
    // the case when it fails
    if(least != 1) {
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] % least == 0)
                count++;
        }
        if(count == n) {
            cout<<-1;
            return 0;
        }
    }
    bool bo_ol = false;
    // the rest of the cases
    while(not_done(arr, n))
    {
        // cout<<"not_done(arr, n) ->"<<not_done(arr, n)<<endl;
        for(int i = 0; i < n-1 && not_done(arr, n); i++)
        {
             cout<<"array is -> ";
             for(int i = 0; i < n; i++)
                 cout<<arr[i]<<" ";
             cout<<endl<<"i is ->"<<i<<endl;
            // cout<<"bo_ol -> "<<bo_ol<<endl;
            if(arr[i] == arr[i+1])
                continue;
            int hcf = gcd(arr[i], arr[i+1]);
            if(hcf == 1 || bo_ol) {
                bo_ol = false;
                if(arr[i+1] != hcf)
                    arr[i+1] = hcf;
                else if(arr[i] != hcf)
                    arr[i] = hcf;
                else {
                    bo_ol = true;
                    continue;
                }
                counter++;
            } else if(i == n-2)
                bo_ol = true;
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

            /*
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
            */
