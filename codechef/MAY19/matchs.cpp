#include<iostream>

using namespace std;

bool solve(long long int m, long long int n)
{
	//cout << "Called solve with " << m << " " << n << "\n";
	if(n%m==0)
		return true;
	if(n/m >= 2)
		return true;
	return !solve(n%m,m);
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long int n, m;
		cin >> n >> m;
		if(m==n)
		{
			cout << "Ari\n";
			continue;
		}
		if(solve(min(m,n),max(m,n)))
			cout << "Ari\n";
		else
			cout << "Rich\n";
	}
}
