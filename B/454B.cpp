#include<iostream>
#include<vector>
using namespace std;

#define PRINT_FAILED    {                   \
                            cout<<"-1";     \
                            return 0;       \
                        }

int main()
{
    long long int n,  min_index = 0,  min_count = 0, temp, bo_ol = 0;
    vector<long long int> arr;
    cin>>n>>temp;
    arr.push_back(temp);
    for(long long int i = 1; i < n; i++)
    {
        // cout<<i<<"<- i\n";
        cin>>temp;
        arr.push_back(temp);
        if(arr[min_index] > arr[i]){
            min_index = i;
            min_count++;
            if(bo_ol >= 1 && min_count > 1)
                PRINT_FAILED
        // cout<<"min_count raised \n";
        }
        if(arr[i - 1] > arr[i] && (arr[i] == arr[min_index]) && i != min_index)
        {
            min_index = i;
            if(++min_count >= 2)
            {
                // cout<<"min_count raised \n";
                PRINT_FAILED
            }
        }
        if(arr[i] == arr[min_index] && i != min_index)
        {
            if(arr[i-1] != arr[i])
            {
                if(i == n-1 && bo_ol == 0)
                {
                    cout<<"1";
                    return 0;
                }
                else if(i == n-1 && bo_ol == n-1)
                {
                    cout<<"0";
                    return 0;
                }
                else
                    bo_ol++;
        }
        if(min_count >= 2)
            PRINT_FAILED
        if(arr[i - 1] > arr[i] && (i != min_index))
        {
            PRINT_FAILED
        }
    }
    if(min_index == 0)
        cout<<"0";
    else
    {
        if(arr[0] >= arr[n-1])
            cout<<n - min_index;
        else
            PRINT_FAILED
    }
}
