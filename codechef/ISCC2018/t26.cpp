#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int start[n];
	int end[n];
	memset(start,0,sizeof(start));
	memset(end,0,sizeof(end));
	int m;
	cin >> m;
	while(m--)
	{
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		start[l]++;
		end[r]++;
	}
	int arr[n];
	int run=0;
	for(int i=0 ; i<n ; i++)
	{
		run+=start[i];
		arr[i] = run;
		run-=end[i];
	}
	int ans[100001];
	memset(ans,0,sizeof(ans));
	for(int i=0 ; i<n ; i++)
	{
		ans[arr[i]]++;
	}
   /* for(int i=0 ; i<7 ; i++)*/
		//cout << ans[i] << " ";
	/*cout << "\n";*/
	int sum = 0;
	for(int i=100000; i>=0 ; i--)
	{
		sum+=ans[i];
		ans[i]=sum;
	}
   /* for(int i=0 ; i<7 ; i++)*/
		//cout << ans[i] << " ";
	//cout << "\n";

	//for(int i=0 ; i<n ; i++)
	//{
		//cout << arr[i] << " ";
	//}
	/*cout << "\n";*/
	int q;
	cin >> q;
	while(q--)
	{
		int k;
		cin >> k;
		cout << ans[k] << "\n";
	}
}
