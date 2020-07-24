#include<iostream>
#include<map>
using namespace std;

#define m1 1000000009

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
	int n, q;
	cin >> n >> q;
	map<unsigned long long int, int> counter;
	for(int i=0 ; i<n ; i++)
	{
		unsigned long long int a, b;
		cin >> a >> b;
		unsigned long long int input = 4*a*b + 2*max(a,b);
		counter[input]++;
	}
	while(q--)
	{
		unsigned long long int k;
		cin >> k;
		unsigned long long int lhs = k*(k+1);
		map<unsigned long long, int>::iterator it;
		it = counter.find(lhs);
		if(it==counter.end())
			cout << -1 << "\n";
		else
			cout << modInverse(it->second,m1) << "\n";
	}
}
