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
		int ans[n][m];
		int row_has_one[n];
		int col_has_one[m];
		memset(row_has_one,0,sizeof(row_has_one));
		memset(col_has_one,0,sizeof(col_has_one));
		bool has_one = false;
		for(int i=0 ; i<n ; i++)
		{
			for(int j=0 ; j<m ; j++)
			{
				char in;
				cin >> in;
				if(in == '1')
				{
					has_one = true;
					ans[i][j] = 0;
					row_has_one[i] = 1;
					col_has_one[j] = 1;
				}
				else
					ans[i][j] = -1;
			}
			
		}
		if(!has_one)
		{
			for(int i=0 ; i<n ; i++)
			{
				for(int j=0 ; j<m ; j++)
				{
					cout << ans[i][j] << " ";
				}
				cout << "\n";
			}
		}
		else
		{
			for(int i=0 ; i<n ; i++)
			{
				if(row_has_one[i])
				{
					for(int j=0 ; j<m ; j++)
					{
						if(ans[i][j]!=0)
							ans[i][j]=1;
					}
				}
			}
			for(int j=0 ; j<m ; j++)
			{
				if(col_has_one[j])
				{
					for(int i=0 ; i<n ; i++)
					{
						if(ans[i][j]!=0)
							ans[i][j]=1;
					}
				}
			}
			for(int i=0 ; i<n ; i++)
			{
				for(int j=0 ; j<m ; j++)
				{
					if(ans[i][j]==-1) ans[i][j]=2;
					cout << ans[i][j] << " ";
				}
				cout << "\n";
			}


		}
	}
}
