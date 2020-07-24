#include<iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		string s;
		cin >> n >> s;
		int output = 0;
		int num_ones = 0;
		int num_zeros = 0;
		for(int i=0 ; i<n ; i++)
		{
			string in;
			cin >> in;
			char start = in[0];
			if(start == '0') num_zeros++;
			else num_ones++;
			int count = 0;
			for(int j=0 ; j<in.length() ; j++)
			{
				if(in[j]!=start)
				{
					start=in[j];
					count++;
				}
			}
			output+=count;
		}
		if(s=="Dee")
		{
			if(num_zeros==0)
			{
				cout << "Dee\n";
				continue;
			}
			else if(output%2==0)
			{
				cout << "Dee\n";
				continue;
			}
			else
			{
				cout << "Dum\n";
				continue;
			}
		}
		else if(s=="Dum")
		{
			if(num_ones==0)
			{
				cout << "Dum\n";
				continue;
			}
			else if(output%2==0)
			{
				cout << "Dum\n";
				continue;
			}
			else
			{
				cout << "Dee\n";
				continue;
			}
		}
	}
}
