#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		pair<unsigned long long int,unsigned long long int> L[n];
		for(int i=0 ; i<n ; i++)
		{
			unsigned long long int l,r;
			cin >> l >> r;
			L[i] = make_pair(l,r);
		}
		sort(L,L+n);
		unsigned long long int temp[n];
		for(int i=0 ; i<n ; i++)
		{
			temp[i] = L[i].first;
		}
		while(m--)
		{
			unsigned long long int p;
			cin >> p;
			unsigned long long int* it = upper_bound(temp,temp+n,p);
			int pos = it - temp - 1;
			if(pos < 0)
			{
				cout << L[0].first - p << "\n";
			}
			else if(pos == n-1)
			{
				if(L[pos].second>p)
					cout << 0 << "\n";
				else cout << -1 << "\n";
			}
			else
			{
				if(L[pos].second>p)
					cout << 0 << "\n";
				else
					cout << L[pos+1].first - p << "\n";
			}
			
		}
	}
}
