#include<iostream>
#include<cmath>
using namespace std;


#define SIZE 10000000
 
bool sieve[SIZE]; 
void primeSieve ( int n ) {
    sieve[0] = sieve[1] = 1; 
    for ( int i = 4; i <= n; i += 2 ) sieve[i] = true; 
    int sqrtn = sqrt ( n );
    for ( int i = 3; i <= sqrtn; i += 2 ) {
        if ( sieve[i] == false ) {
            for ( int j = i * i; j <= n; j += 2 * i ) sieve[j] = true;
        }
    }
}


/*bool approximatelyEqual(long double a, long double b, double absEpsilon, double relEpsilon)
{
    long double diff = fabs(a-b);
    if(diff <= absEpsilon)
        return true;
    // fabs fxn give the modulus of the value passed to it
    return fabs(a-b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a))*relEpsilon);
}
*/
int main()
{
    int n;
    cin>>n;
    long long int x;
    //double relEpsilon = 1e-12;
    //double absEpsilon = 1e-14;
    primeSieve(SIZE);
    for(int i = 0; i < n; i++)
    {
        cin>>x;
        //long double y = sqrt(x);
        long long y = floor(sqrt(x)+0.00000001);
        //if(approximatelyEqual(x, (int)y*y, absEpsilon, relEpsilon))
        if( y * y == x)
        {
            if(!sieve[y])
                cout<<"YES\n";
            else
                cout<<"NO\n";
            //cout<<"perfect square\ty is"<<y;
            /*
            if(y <= 1){
                cout<<"NO\n";
                continue;
            }
            if(y<=3){
                cout<<"YES\n";
                continue;
            }
            if((int)y % 2 == 0 || (int)y % 3 == 0)
            {
                cout<<"NO\n";
                continue;
            }
            
            cout<<" remainder is -> "<<((int)y) % 6<<"\t";
            if( approximatelyEqual(((int) y) % 6, (double)1, absEpsilon, relEpsilon) || approximatelyEqual((int)y) % 6, (double)5, absEpsilon, relEpsilon))
                cout<<"YES\n";
            else
                cout<<"NO\n";
             
            for(int j = 5; j*j <= y; j += 6 )
            {
                if((int)y % j == 0 || (int)y % (j + 2) == 0){
                    cout<<"NO";
                    goto here;
                }
            }
            cout<<"YES";
            here:
            cout<<"\n";
            */
        }
        else
        {
            cout<<"NO\n";
        }
    }
}
