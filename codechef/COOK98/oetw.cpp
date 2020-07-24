#include<iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int a[n];
		int sum=0;
		for(int i=0 ; i<n ; i++)
		{
			cin >> a[i];
			sum+=a[i];
		}
		int id = 0;
		while(id<n)
		{
			if(a[id]==1||a[n-id-1]==1)
				break;
			sum--;
			id++;
		}
		cout << sum << endl;
	}
}
