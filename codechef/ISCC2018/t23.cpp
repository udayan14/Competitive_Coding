#include<iostream>

#define N 100001 
using namespace std;
bool prime[N];

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		bool has_one = false;
		int a[n];
		for(int i=0 ; i<n ; i++)
		{
			int in;
			cin >> in;
			a[i] = in;
			if(a[i]==1)
			{
				has_one = true;
			}
		}
		if(has_one)
		{
			cout << "YES\n";
		}
		else
		{
			for(int i=0 ; i<n-1 ; i++)
			{
			
				for(int j=i+1 ; j<n ; j++)
				{
					if(gcd(a[i],a[j])==1)
					{
						has_one = true;
						break;
					}
						
				
				}
				if(has_one)
					break;
			}
			if(has_one)
				cout << "YES\n";
			else cout << "NO\n";
		}
	}
}
