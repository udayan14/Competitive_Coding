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
		unsigned long long int a[n+1];
		cout << "1 1 2 3\n";
		unsigned long long int b1,b2,b3,b4;
		cin >> b4;
		cout << "1 2 3 4\n";
		cin >> b1;
		cout << "1 1 2 4\n";
		cin >> b3;
		cout << "1 1 3 4\n";
		cin >> b2;
		unsigned long long int temp14 = b1^b4;
		a[2] = b3^temp14;
		a[3] = b2^temp14;
		a[1] = b4^a[2]^a[3];
		a[4] = b3^a[1]^a[2];
		for(int i=5 ; i<=n ; i++)
		{
			cout << "1 1 2 "<< i << "\n";
			unsigned long long int temp;
			cin >> temp;
			if(temp==-1)
				return 0;
			a[i] = temp^a[1]^a[2];
		}
		cout << 2 << " ";
		for(int i=1 ; i<=n ; i++)
			cout << a[i] << " ";
		cout << "\n";
		int temp;
		cin >> temp;
		if(temp==-1)
			return 0;
	}
}
