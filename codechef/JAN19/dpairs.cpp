#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	pair< int,int > a[n];
	pair< int,int > b[m];
	for(int i=0 ; i<n ; i++)
	{
		int in;
		cin >> in;
		a[i] = make_pair(in,i);
	}
	for(int i=0 ; i<m ; i++)
	{
		int in;
		cin >> in;
		b[i] = make_pair(in,i);
	}

	sort(a,a+n);
	sort(b,b+m);
	for(int i=0 ; i<n ; i++)
		cout << a[i].second << " " << b[0].second << "\n";
	for(int i=1 ; i<m ; i++)
		cout << a[n-1].second << " " << b[i].second << "\n";
}
