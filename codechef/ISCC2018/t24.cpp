#include<iostream>

using namespace std;
#define m1 1000000007

long long int modexp(long long int x, long long int y, long long int p)
{
    long long int out = 1;
    x = x % p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            out = ((out%p)*(x%p)) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = ((x%p)*(x%p)) % p;  
    }
    return out;
}

unsigned long long modInverse(long long int a, long long int m)
{
	return modexp(a, m-2, m);
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		if(k==1)
			cout << 1 << "\n";
		else
			cout << (((((modexp(k,n+1,m1)-1)%m1)*(modInverse(k-1,m1)%m1))%m1)-1)%m1 << "\n";
	}
}
