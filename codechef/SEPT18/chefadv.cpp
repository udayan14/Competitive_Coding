#include<iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m,x,y;
		cin >> n >> m >> x >> y;
		n--;
		m--;
		int r1 = n%x;
		int r2 = m%y;
		if(n==0 && m==0)
			cout << "Chefirnemo\n";
		else if(n==1 && m==1)
			cout << "Chefirnemo\n";
		else if(r1==0 && r2==0)
			cout << "Chefirnemo\n";
		else if(r1==1 && r2==1)
			cout << "Chefirnemo\n";
		else if(x==1 && y==1)
			cout << "Chefirnemo\n";
		else if(x==1 && n!=0 && r2==1)
			cout << "Chefirnemo\n";
		else if(y==1 && m!=0 && r1==1)
			cout << "Chefirnemo\n";
		else
			cout << "Pofik\n";
	}
}
