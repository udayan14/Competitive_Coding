#include<iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a,b,c,x,y;
		cin >> a >> b >> c >> x >> y;
		if(a+b+c!=x+y)
			cout << "NO\n";
		else
		{
			int m1 = min(a,min(b,c));
			int m2 = min(x,y);
			if(m2<m1)
				cout << "NO\n";
			else 
				cout << "YES\n";
		}
	
	}
}
