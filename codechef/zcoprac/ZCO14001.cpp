#include<iostream>

using namespace std;

int main()
{	
	int n,h;
	cin >> n >> h;
	int a[n];
	for(int i=0 ; i<n ; i++)
		cin >> a[i];
	int pos = 0;
	int has_block = 0;
	int inp;
	cin >> inp;
	while(inp!=0)
	{
		if(inp==1)
		{
			if(pos>0)
				pos--;
		}
		else if(inp==2)
		{
			if(pos<n-1)
				pos++;
		}
		else if(inp==3)
		{
			if(has_block==0 && a[pos]>0)
			{
				has_block = 1;
				a[pos]--;
			}
		}
		else if(inp==4)
		{
			if(has_block==1 && a[pos]<h)
			{
				has_block = 0;
				a[pos]++;
			}
		}
		cin >> inp;
	}
	for(int i=0 ; i<n ; i++)
		cout << a[i] << " ";
	cout << "\n";
}
