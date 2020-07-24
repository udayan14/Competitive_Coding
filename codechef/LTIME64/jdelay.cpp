#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int count = 0;
		while(n--)
		{
			int s,j;
			cin >> s >> j;
			if(j>s+5)
				count++;
		}
		cout << count << "\n";
	}
}
