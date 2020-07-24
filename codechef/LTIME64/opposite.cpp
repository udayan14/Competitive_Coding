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
				int a[n];
		for(int i=0 ; i<n ; i++)
		{
			cin >> a[i];
		}
		if(n%2==1)
		{
			cout << "NO\n";
			continue;
		}
		int j = n/2;
		int flag = true;
		for(int i=0 ; i<n/2 ; i++)
		{
			if(a[i]==a[j] && a[j]==-1)
			{
				a[i]=a[j]=1;
			}
			else if(a[i]!=a[j] && a[i]==-1)
				a[i] = a[j];
			else if(a[i]!=a[j]&& a[j]==-1)
				a[j] = a[i];
			else if(a[i]!=a[j])
			{
				cout << "NO\n";
				flag = false;
				break;
			}
			j = (j+1)%n;
		}
		if(!flag) continue;
		cout << "YES\n";
		for(int i=0 ; i<n ; i++)
			cout << a[i] << " ";
		cout << "\n";
	}
}
