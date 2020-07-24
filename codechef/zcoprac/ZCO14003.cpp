#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	long long int n;
	cin >> n;
	long long int a[n];
	long long int output = 0;
	for(int i=0 ; i<n ; i++)
		cin >> a[i];
	sort(a,a+n);
	for(long long int i=0 ; i<n ; i++)
		output = max(output,a[i]*(n-i));
	cout << output << "\n";
}
