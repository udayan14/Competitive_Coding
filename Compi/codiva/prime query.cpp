#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
# define N 1000001


 bool prime[N];

void SieveOfEratosthenes()
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    prime[0] = false;
    prime[1] = false;
    memset(prime, true, sizeof(prime)); 
    for (int p=2; p<N; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<N; i += p)
                prime[i] = false;
        }
    }
}

int main()
{
    memset(prime,true,sizeof(prime));
    SieveOfEratosthenes();
    int q;
    cin >> q;
    while(q--){
        int l , r;
        cin >> l >> r;

        int out = 0;
        for (int i = l; i <= r ; ++i)
        {
            if(prime[i]){
                out += -i;
                break;
            }
        }
        for (int i = r; i >= l ; i--)
        {
            if(prime[i]){
                out += i;
                break;
            }
        }
        cout << out << endl;        
    }
}