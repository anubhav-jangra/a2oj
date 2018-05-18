#include <iostream>
#include <string>
#include <unordered_map>
#include<iterator>
using namespace std;

int main()
{
    string s;
    cin>>s;
    unordered_map<char, int> umap;
    umap['h'] = 0;
    umap['e'] = 0;
    umap['l'] = 0;
    umap['o'] = 0;
    char alpha[] = {'h', 'e', 'l', 'o'};
    int i = 0, j = 1;
    while(s[i] != '\0' && s.at(i) != 'h')
        i++;
    if(s[i] == 'h')
    {
        i++;
        umap['h'] == 1;
    }
    else if(s[i] == '\0')
    {
        printf("NO");
        return 0;
    }
    for(i; i < s.size() && s[i] != '\0'; i++)
    {
        if(s[i] == alpha[j-1])
            continue;
        if(s[i] == alpha[j])
        {
            umap[alpha[j]] += 1;
            if(j != 2)
                j++;
            else if(umap['l'] == 2)
                j++;
        }
        if(j==4)
        {
            cout<<"YES";
            return 0;
        }
    }
    printf("NO");
    return 0;
}
