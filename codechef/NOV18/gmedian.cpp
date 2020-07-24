#include <iostream>
#include <cstring>

#define m 1000000007
using namespace std;

long long int choose[1001][1001];

long long int power(long long int x, unsigned long long int y, long long int p) 
{ 
    long long int res = 1;      // Initialize result 
  
    x = x % p;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p;   
    } 
    return res; 
}

int main()
{
	memset(choose,0,sizeof(choose));
	for(int i=0 ; i<1001 ; i++)
	{
		for(int j=0 ; j<=i ; j++)
		{
			if(j==i || j==0)
				choose[i][j] = 1;
			else
			{
				choose[i][j] = (choose[i-1][j] + choose[i-1][j-1])%m;
			}
		}
	}
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int a[n];
		int freq[2*n+1];
		memset(freq,0,sizeof(freq));
		for(int i=0 ; i<n ; i++)
		{
			int in;
			cin >> in;
			freq[in]++;
		}
		int prefix_sum[2*n+1];
		prefix_sum[0] = 0;
		for(int i=1 ; i<2*n+1 ; i++)
			prefix_sum[i] = prefix_sum[i-1] + freq[i];
		long long int ans = power(2,n-1,m);
		for(int i=1 ; i<2*n+1 ; i++)
		{
			if(freq[i]>1)
			{
				long long int acc = 0;
				int left = prefix_sum[i-1];
				int right = prefix_sum[2*n] - prefix_sum[i];
				for(int j=0 ; j<=min(left,right) ; j++)
					acc = (acc+(choose[left][j]*choose[right][j])%m)%m;
				ans=(ans+(choose[freq[i]][2]*acc)%m)%m;
			}
		}
		cout << ans << "\n";
	}
}
