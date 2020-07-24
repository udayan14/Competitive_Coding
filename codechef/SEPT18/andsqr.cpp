#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,q;
		cin >> n >> q;
		unsigned long long int a[n];
		for(int i=0 ; i<n ; i++)
			cin >> a[i];
		while(q--)
		{
			int l,r;
			cin >> l >> r;
			l--;
			r--;
			int output = 0;
			for(int i=l ; i<=r ; i++)
			{
				unsigned long long int acc = 0xFFFFFFFFul;
				for(int j=i ; j<=r ; j++)
				{
					acc&=a[j];
					long double sr = sqrt(acc);
					if((sr-floor(sr))==0)
						output++;
				}
			}
			cout << output << "\n";
		}
	}
}
