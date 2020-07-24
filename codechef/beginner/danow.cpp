#include<iostream>

using namespace std;

int main()
{
	int n,q;
	cin >> n >> q;
	long int a[n+1];
	long int b[n+1];
	for(int i=1 ; i<=n ; i++)
		cin >> a[i];
	for(int i=1 ; i<=n ; i++)
		cin >> b[i];
	a[0] = b[0] = 0;
	long long int output[n+1];
	output[0] = 0;
	for(int i=1 ; i<=n ; i++)
		output[i] = output[i-1] + a[i]*b[i];
	while(q--)
	{
		int l,r;
		cin >> l >> r;
		cout << output[r] - output[l-1] << "\n";
	}
}
