#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		int in;
		int count = 0;
		for(int i=0 ; i<n ; i++)
		{
			cin >> in;
			if(in%m==0)
				count++;
		}
		if(count==0)
			cout << 0 << "\n";
		else
		{
		int output = 1<<count;
		cout << output-1 << "\n";
		}
	}
}
