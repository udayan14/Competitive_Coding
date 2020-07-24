#include<iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		string s;
		cin >> n >> s;
		int i = 0;
		while(i+1<n)
		{
		char temp = s[i];
		s[i] = s[i+1];
		s[i+1] = temp;
		i+=2;
		}
		for(int i=0 ; i<n ; i++)
		{
			s[i] = 25 - (s[i] - 'a') + 'a';
		}
		cout << s << "\n";
	}
}
