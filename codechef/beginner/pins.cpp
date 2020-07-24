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
		cout <<"1 1";
		for(int i=0; i<n/2 ; i++)
			cout << 0;
		cout << "\n";
	}
}
