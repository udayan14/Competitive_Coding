#include<iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,x,s;
		cin >> n >> x >> s;
		int curr = x;
		while(s--)
		{
			int a,b;
			cin >> a >> b;
			if(curr==a)
				curr=b;
			else if(curr==b)
				curr=a;
		}
		cout << curr << "\n";
	}
}
