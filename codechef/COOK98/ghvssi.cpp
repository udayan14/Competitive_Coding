#include <iostream>
#include <cstring>

#define N 301
int ans[N][N][N][4];
using namespace std;

int solve(int a, int b, int c, int d)
{
	if(a<0 || b<0 || c<0)
		return 1;
	if(d==2)
		return 1;
	if(ans[a][b][c][d]!=-1)
		return ans[a][b][c][d];
	int temp = min(solve(a-1,b,c,(d+1)%4),min(solve(a,b-1,c,(d+2)%4),solve(a,b,c-1,(d+3)%4)));
	temp^=1;
	ans[a][b][c][d]=temp;
	return temp;
}


int main()
{
	int t;
	cin >> t;
	for(int i=0 ; i<N ; i++)
		for(int j=0 ; j<N ; j++)
			for(int k=0 ; k<N ; k++)
				for(int l=0 ; l<4 ; l++)
					ans[i][j][k][l]=-1;
	while(t--)
	{
		int n;
		cin >> n;
		int a[4];
		memset(a,0,sizeof(a));
		for(int i=0 ; i<n ; i++)
		{
			int in;
			cin >> in;
			a[in%4]++;
		}
		int ret = solve(a[1],a[2],a[3],0);
		if((a[0]%2)==1)
			ret^=1;
		if(ret)
			cout << "Ghayeeth\n";
		else cout << "Siroj\n";
	}
}

