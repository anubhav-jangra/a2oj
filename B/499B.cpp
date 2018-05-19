#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int n, m, j;
    cin>>n>>m;
    string str;
    vector<string> arr1;
    vector<string> arr2;
    vector<string>::iterator i;
    for(int i = 0; i < m; i++)
    {
        cin>>str;
        arr1.push_back(str);
        cin>>str;
        arr2.push_back(str);
    }
    for(int i = 0; i < n; i++)
    {
        cin>>str;
        for(j = 0; str != arr1[j]; j++);
        if(arr1[j].length() <= arr2[j].length())
            cout<<arr1[j]<<" ";
        else
            cout<<arr2[j]<<" ";
    }
}
