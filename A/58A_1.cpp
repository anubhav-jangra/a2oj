#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cin>>s;
    char str[] = {'h', 'e', 'l', 'l', 'o'};
    int i = 0;
    for(auto e: s)
    {
        if(e == str[i])
        {
            i++;
            if(i == 5)
                break;
            continue;
        }
    }
    if(i == 5)
        cout<<"YES";
    else
        cout<<"NO";

    
    return 0;
}
