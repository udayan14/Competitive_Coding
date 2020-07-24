#include<iostream>
#include<cstring>

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
		int count = 0;
		memset(a,0,sizeof(a));
		for(int i=0 ; i<n ; i++)
		{
			int in;
			cin >> in;
			in--;
			if(in<n && a[in]==0)
			{
				a[in]++;
				count++;
			}
		}
		cout << n-count << "\n";
	}
}
