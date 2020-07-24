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
		int num_pos = 0;
		int num_neg = 0;
		int num_zero = 0;
		for(int i=0 ; i<n ; i++)
		{
			int in;
			cin >> in;
			if(in>0)
				num_pos++;
			else if(in<0)
				num_neg++;
			else
				num_zero++;
		}
		if(num_pos==0)	
		{
			if(num_neg == n)
				cout << n << " " << n << "\n";
			else
				cout << n << " " << 1 << "\n";
		}
		else
		{
			if(num_neg==0)
			{
				if(num_pos==n)
					cout << n << " " << n << "\n";
				else
					cout << n << " " << 1 << "\n";
			}
			else
			{
				if(num_zero==0)
				{
					cout << max(num_neg,num_pos) << " " << min(num_neg,num_pos) << "\n";
				}
				else
					cout << num_zero + max(num_neg,num_pos) << " " << 1 << "\n";
			}
		}
	}
}
