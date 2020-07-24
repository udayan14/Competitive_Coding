#include<iostream>
#include<cstring>
using namespace std;

#define m 1000000007

long long int solve(int i, int a[], long long int ans[], int n)
{

   /* cout << "Solve called with " << i << " " << n << "\n";*/
	//for(int i=1 ; i<=n ; i++)
		//cout << ans[i] << " ";
	/*cout << "\n";*/
	if(ans[i]!=-1)
	{
		return ans[i];
	}
	else
	{
		if(i==n)
		{
			ans[i] = 1;
			return 1;
		}
		else if(i==n-1)
		{
			ans[i] = 2;
			return 2;
		}
		else
		{
			if(a[i]==1)
			{
				long long int temp = (1+solve(i+1,a,ans,n))%m;
				ans[i] = temp;
				return temp;
			}
			else
			{
				long long int temp = ((2 + solve(i+1,a,ans,n))%m + solve(i+2,a,ans,n))%m;
				if(a[i+1]==2 && i+3<=n)
					temp = (temp + solve(i+3,a,ans,n))%m;
				ans[i] = temp;
				return temp;
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int a[n+1];
		for(int i=1 ; i<=n ; i++)
			cin >> a[i];
		long long int ans[n+1];
		memset(ans,-1,sizeof(ans));
		cout << solve(1,a,ans,n) << "\n";
	}
}
