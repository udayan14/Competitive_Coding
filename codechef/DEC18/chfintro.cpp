#include<iostream>

using namespace std;

int main()
{
	int n,r;
	cin >> n >> r;
	while(n--)
	{
		int in;
		cin >> in;
		if(in>=r)
			cout << "Good boi\n";
		else 
			cout << "Bad boi\n";
	}
}
