#include<iostream>
#define m 1000000007
#define Nmax 1001
using namespace std;

long long int f[Nmax][Nmax];
long long int g[Nmax][Nmax];


int main()
{
	for(int i=0 ; i<Nmax ; i++)
	{
		for(int j=0 ; j<Nmax ; j++)
		{
			if(j==0)
			{
				f[i][j] = 1;
				g[i][j] = 1;
			}
			else if(j==1)
			{
				f[i][j] = 2*i;
				g[i][j] = 2*i-1;
			}
			else if(j>i)
			{
				f[i][j] = 0;
				g[i][j] = 0;
			}
			else if(j==i)
			{
				f[i][j] = 2;
				g[i][j] = 1;
			}
			else
			{
				f[i][j] = ((2*g[i-1][j-1])%m + f[i-1][j])%m;
				g[i][j] = (g[i-1][j-1] + f[i-1][j])%m;
			}
		}
	}
	int t;
	cin >> t;
	while(t--)
	{
		long long int n,k;
		cin >> n >> k;
		cout << f[n][k] << "\n";
	}
}
