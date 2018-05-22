#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

inline int read_char()
{
    char c;
    scanf("%c", &c);
    if(c != '\0')
        return c - '0';
    else
        return -1;
}

int main()
{
    int a, b = 0;
    long int i = -1;
    vector <long int> arr[5];     // 0 2 4 6 8
    bool bo_ol = false;
    vector<int> data;
    a = read_char();
    do
    {
        data.push_back(a);
        i++;
//        cout<<"DATA IS -> ";
//        for(int ir = 0; ir < data.size(); ++ir)
//            cout<<data[ir];
//        cout<<endl;
        if(a % 2 == 0)
        {
//            cout<<"encountered even number here -> "<<a<<endl;
            if(!bo_ol)
                bo_ol = true;
            (arr[a/2]).push_back(i);
        }
        b = a;
        a = read_char();
    }while(a >= 0);

    if(!bo_ol)
        cout<<"-1";
    else 
    {
//        cout<<"arr -> ";
//        for(int i = 0; i < 5; i++)
//            if(!arr[i].empty())
//                for(long int ir = 0; ir < arr[i].size(); ++ir)
//                    cout<<arr[i].at(ir);
//            else
//                cout<<"=====0 - khaali h ye=====";
//        cout<<endl<<"b/2 is "<<b/2<<endl;
        b /= 2;
        long int min_index = 1000000, max_index = 0;
        bool done = false;
        
        for(int i = 0; i <= b; i++)
            if(!arr[i].empty())
                for(long int ir = 0; ir < arr[i].size(); ++ir)
                    if(min_index > arr[i].at(ir))
                    {
//                        cout<<"min index is now -> "<<min_index<<endl;
                        min_index = arr[i].at(ir);
                    }
//            else
//                cout<<"bypassed min_index part..."<<endl;
        
        if(min_index != 1000000)
        {
//            cout<<"swapped via min_index"<<endl;
            swap(data[min_index], data.back());
            done = true;
        }
        
        if(!done)
        {
            for(int i = 4; i > b; i--)
                if(!arr[i].empty())
                    for(long int ir = 0; ir < arr[i].size(); ++ir)
                        if(max_index < arr[i].at(ir))
                        {
//                            cout<<"max index is now -> "<<max_index<<endl;
//                            cout<<"and arr[i].at(ir) is -> "<<arr[i].at(ir)<<endl;
                            max_index = arr[i].at(ir);
                        }
//            cout<<"swapped via max_index"<<endl;
            swap(data[max_index], data.back());
        }
//      cout<<"DATA IS -> ";
        for(long int ir = 0; ir < data.size(); ++ir)
            cout<<data[ir];
    }
}
