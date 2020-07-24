#include<iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,q;
		long long int a[n];
		long long int b[n];
		cin >> n >> q;;
		for(int i=0 ; i<n ; i++)
			cin >> a[i];
		for(int i=0 ; i<n ; i++)
			cin >> b[i];
		
		long long int pr=0;
		for(int i=0 ; i<n ; i++)
			if(a[i]==b[i])
				pr++;
		while(q--)
		{
			unsigned long long int x,y,z,l,r,c;
			cin >> x >> y >> z;
			l = x ^ pr;
			r = y ^ pr;
			c = z ^ pr;
			l--;
			r--;
			for(int i=l ; i<=r ; i++)
			{
				if(a[i]==b[i] && a[i]!=c)
					pr--;
				else if(a[i]!=b[i] && b[i]==c)
					pr++;
				a[i] = c;
			}
			cout << pr << "\n";
		}
	}
}
