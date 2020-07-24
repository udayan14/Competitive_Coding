#include<iostream>

using namespace std;

const int N=1e6+5;
int row[3][N];
int col[N][3];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		string m1;
		cin >> m1;
		string n1;
		cin >> n1;
		int m = m1.length();
		int n = n1.length();
		m1 = 'a' + m1;
		n1 = 'a' + n1;

		if(m1[1]=='0'||n1[1]=='0')
		{
			row[1][1]=1;
			col[1][1]=1;
		}
		else
		{
			row[1][1]=0;
			col[1][1]=0;
		}
		for(int i=2 ; i<=m ; i++)         //row1
		{
			if(row[1][i-1]==1 && m1[i]=='1')
				row[1][i]=0;
			else
				row[1][i]=1;
		}
		for(int j=2 ; j<=n ; j++)       //col1
		{
			if(col[j-1][1]==1 && n1[j]=='1')
				col[j][1]=0;
			else
				col[j][1]=1;
		}
		row[2][1] = col[2][1];
		col[1][2] = row[1][2];
		if(row[1][2]==0 || col[2][1]==0)
			row[2][2]=col[2][2]=1;
		else
			row[2][2]=col[2][2]=0;
		for(int i=3 ; i<=m ; i++)
		{
			if(row[2][i-1]==1 && row[1][i]==1)
				row[2][i]=0;
			else
				row[2][i]=1;
		}
		for(int j=3 ; j<=n ; j++)
		{
			if(col[j-1][2]==1 && col[j][1]==1)
				col[j][2]=0;
			else
				col[j][2]=1;
		}
		int q;
		cin >> q;
		while(q--)
		{
			int x,y;
			cin >> x >> y;
			int d = min(x,y);
			if(d>2)
			{
				x=x-d+2;
				y=y-d+2;
			}
			if(x<=2)
				cout << row[x][y];
			else
				cout << col[x][y];
		}
	}
}
