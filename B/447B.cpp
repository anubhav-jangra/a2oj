#include<iostream>
#include<string>
using namespace std;

int arr[26];

int findValue(string str)
{
    int sum = 0;
    for(int i = 0; i < str.length(); i++)
    {
        //cout<<"added -> "<<arr[ str[i] - 97] * (i+1);
        sum += arr[ str[i] - 97] * (i+1);
    }
    return sum;
}

int findMax()
{
    int max_index = 0;
    for(int i = 1; i < 26; i++)
    {
        if(arr[max_index] < arr[i])
            max_index = i;
    }
    return max_index;
}

int main()
{
    string s;
    int k;
    cin>>s>>k;
    for(int i = 0; i < 26; i++)
        cin>>arr[i];
    int max_index = findMax();
    //cout<<"\nMax index is -> "<<max_index<<endl;
    //cout<<"\nStr length is -> "<<s.length()<<endl;
    cout<<(     findValue(s) + arr[max_index] * ( k * s.length() + (k*(k+1))/2 )   );
}
