#include<iostream>
#include<vector>
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
		int a[n+1];
		int freq[n+1];
		vector <vector <int> > b(n+1);
		memset(freq,0,sizeof(freq));
		for(int i=1 ; i<=n ; i++)
		{
			int in;
			cin >> in;
			a[i] = in;
			freq[in]++;
			b[a[i]].push_back(i);
		}
		int flag = 0;
		for(int i=1 ; i<=n ; i++)
		{
			int count = 0;
			for(int j=0 ; j<b[i].size() ; j++)
			{
				if(freq[b[i][j]]>0)
					count++;
			}
			if(count>1)
			{
				cout << "Truly Happy\n";
				flag = 1;
				break;
			}
		}
		if(!flag)
			cout << "Poor Chef\n";
	}
}
