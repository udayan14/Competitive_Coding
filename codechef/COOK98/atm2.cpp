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
		long long int k;
		cin >> n >> k;
		for(int i=0 ; i<n ; i++)
		{
			long long int in;
			cin >> in;
			if(in<=k)
			{
				k-=in;
				cout << 1;
			}
			else
				cout << 0;
		}
		cout << "\n";
	}
}

