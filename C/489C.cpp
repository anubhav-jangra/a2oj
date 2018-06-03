#include<iostream>
using namespace std;

int main()
{
    int m, s;
    cin>>m>>s;
    int a[m] = {};
    a[0] = 1;
    int p, q, i;
    bool bo_ol = false;
    if((s == 0 && m > 1) || m == 0 || (m == 1 && s > 9) || s > m * 9) {
        cout<<"-1 -1";
        return 0;
    } else if(s == 0 && m == 1) {
        cout<<"0 0";
        return 0;
    } else if(m == 1 && s <= 9) {
        cout<<s<<" "<<s;
        return 0;
    }
    p = s / (m - 1);
    if(p <= 9) {
        for(i = 1; i < m && p * i + 1 <= s; i++) {
//            cout<<"a["<<i<<"] -> "<<p;
            a[i] = p;
        }
        if(i < m) {
//            cout<<"a["<<i<<"] -> "<<s - (p * (i - 1) + 1);
            a[i] = s - (p * (i - 1) + 1);
        }
    }
    else {
        bo_ol = true;
        p = s/ m;
        for(i = 0; i < m && p * (i+1) <= s; i++) {
//            cout<<"a["<<i<<"] -> "<<p;
            a[i] = p; 
        }
        if(i < m) {
//            cout<<"a["<<i<<"] -> "<<s - (p * (i));
            a[i] = s - (p * (i));
        }
    }
//    cout<<"p is -> "<<p<<endl;
    if(bo_ol)
        q = s - p * m;
    else 
        q = (s - p * (m - 1) - 1 > 0? s - p * (m - 1) - 1 : 0);
//    cout<<"q is -> "<<q<<endl;
    i = m - 1;
    while(q) {
        while(a[i] != 9 && q != 0) {
            a[i]++;
            q--;
        }
        if(q != 0)
            i--;
    }
//    cout<<"i is -> "<<i<<endl;
    if(a[i] == 9)
        i--;
    int min, j = 0;
    while(j < i) {
        if(j == 0)
            min = 1;
        else 
            min = 0;
        while(a[j] != min && a[i] != 9) {
            a[j]--;
            a[i]++;
        }
        if(a[j] == min)
            j++;
        else 
            i--;
    }
    if(a[0] == 0)
        cout<<"-1";
    else
        for(int i = 0; i < m; i++)
            cout<<a[i];
    i = m - 1;
    j = 0;
    while(j < i) {
        while(a[j] != 0 && a[i] != 9) {
            a[j]--;
            a[i]++;
        }
        if(a[j] == 0)
            j++;
        else 
            i--;
    }
    cout<<" ";
    for(int i = m - 1; i >= 0; i--)
        cout<<a[i];
    return 0;
}
