#include<iostream>

#define m 1000000007
using namespace std;

 int main()
{
	long long int a[1000001];   //a[i] = (i+1)! - 1
	a[1] = 1;
	for(int i=2 ; i<1000001 ; i++)
	{
		a[i] = ((((a[i-1]+1)%m)*(i+1))%m - 1)%m;
	}
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << a[n] << "\n";
	}
}
