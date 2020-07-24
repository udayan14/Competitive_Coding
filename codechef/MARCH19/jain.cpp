#include<iostream>
#include<string>
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
		int a[32];
		memset(a,0,sizeof(a));
		for(int i=0 ; i<n ; i++)
		{
			string s;
			cin >> s;
			int temp = 0;
			for(int j=0 ; j<s.length() ; j++)
			{
				if(temp==31)
					break;
				if(s[j]=='a')
					temp|=1;
				else if(s[j]=='e')
					temp|=2;
				else if(s[j]=='i')
					temp|=4;
				else if(s[j]=='o')
					temp|=8;
				else if(s[j]=='u')
					temp|=16;
			}
			a[temp]++;
		}
		long long int output = 0;
		for(int i=0 ; i<32 ; i++)
		{
			for(int j=i+1 ; j<32 ; j++)
			{
				if((i|j)==31)
					output+=a[i]*a[j];
			}
		}
		output+=(a[31]*(a[31] - 1))/2;
		cout << output << "\n";
	}
}
