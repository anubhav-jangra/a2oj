#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cin>>s;
    bool bo_ol = false;
    for(int i = 0; i < s.length(); i++)
    {
//        cout<<"\ni is -> "<<i<<endl;
        if(s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B')
        {
//            cout<<"\nandar\n";
            if(bo_ol)
            {
                cout<<" ";
                bo_ol = false;
            }
            i = i + 2;
        }
        else
        {
            cout<<s[i];
            bo_ol = true;
        }
    }
}
