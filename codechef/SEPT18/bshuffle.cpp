#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin  >> n;
	if(n==1)
		cout << 1 << "\n" << 1 << "\n";
	else
	{
		for(int i=2 ; i<=n/2 ; i++)
			cout << i << " ";
		cout << 1 << " ";
		for(int i=n/2+2 ; i<=n ; i++)
			cout << i << " ";
		cout << n/2+1 << "\n";

		cout << n << " ";
		for(int i=1 ; i<n ; i++)
			cout << i << " ";
	}
}
