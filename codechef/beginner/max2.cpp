#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	char a[n];
	for(int i=0 ; i<n ; i++)
		cin >> a[i];
	int output = 0;
	for(int i=n-1 ; i>=0 ; i--)
	{
		if(a[i]=='1')
			break;
		output++;
	}
	cout << output << "\n";
}
