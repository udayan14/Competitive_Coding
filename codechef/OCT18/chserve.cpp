#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long int k,p1,p2;
		cin >> p1 >> p2 >> k;
		int ans = (p1+p2)%(2*k);
		if(ans<k)
			cout << "CHEF\n";
		else cout << "COOK\n";
	}
}
