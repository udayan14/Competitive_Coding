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
		int count = 0;
		bool flag = false;
		int a[n];
		for(int i=0 ; i<n ; i++)
		{
			cin >> a[i];
		}
		for(int i=0 ; i<n ; i++)
		{
			if(a[i]==1)
				count++;
			else 
				count--;
			if(count<0)
			{
				flag = true;
				break;
			}
		}
		if(!flag)
			cout << "Valid\n";
		else
			cout << "Invalid\n";
	}
}
