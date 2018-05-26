#include<iostream>
#include<cmath>
using namespace std;

unsigned long int distance(long long int x0, long long int y0, long long int  x, long long int y)
{
//    cout<<"\n distance squared is -> "<<(x - x0)*(x - x0) <<"///"<< (y - y0)*(y - y0)<<endl;
    unsigned long int ans = ceil(sqrt((x - x0)*(x - x0) + (y - y0)*(y - y0)));
    return ans;
}
/*
int find_min(int r, int x0, int y0, int x, int y)
{
//    cout<<"in find_min with r -> "<<r<<" x0 -> "<<x0<<" y0 -> "<<y0<<" x -> "<<x<<" y -> "<<y<<endl;
    static int count;
    if(x == x0 && y == y0)
        return count;
    count++;
    if(distance(x0, y0, x, y) <= 2*r)
        return count;
    if(abs(x - x0) <= r && abs(x - x0) != 0)
            return find_min(r, x, y0, x, y);
    else if(abs(y0 - y) <= r && abs(y - y0) != 0)
            return find_min(r, x0, y, x, y);
    else if(x - x0 > r)
    {
        if(y - y0 > r)
            return find_min(r, x0 + r, y0 + r, x, y);
        else if(y0 == y)
            return find_min(r, x0 + 2*r, y0, x, y);
        else
            return find_min(r, x0 + r, y0 - r, x, y);
    }
    else if(x0 - x > r)
    {
        if(y - y0 > r)
            return find_min(r, x0 - r, y0 + r, x, y);
        else if(y0 == y)
            return find_min(r, x0 - 2*r, y0, x, y);
        else
            return find_min(r, x0 - r, y0 - r, x, y);
    }
    else if(x0 == x)
    {
        if(y - y0 > r)
            return find_min(r, x0, y0 + 2*r, x, y);
        else
            return find_min(r, x0, y0 - 2*r, x, y);
    }

}
*/

int find_min(int r, int x0, int y0, int x, int y)
{
    unsigned long int dist = distance((long int)x0, (long int)y0, (long int)x, (long int)y);
//    cout<<"distance is -> "<<dist<<endl;
    int number = ceil((long double)dist/(2*r));
    return (int) number;
}

int main()
{
    int r, x0, y0, x, y;
    cin>>r>>x0>>y0>>x>>y;
    int ans = find_min(r, x0, y0, x, y);
    cout<<ans;
}
