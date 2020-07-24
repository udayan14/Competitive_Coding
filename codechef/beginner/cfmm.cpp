#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int counter[26];
		memset(counter,0,sizeof(counter));
		for(int i=0 ; i<n ; i++)
		{
			string s;
			cin >> s;
			for(int j=0 ; j<s.length() ; j++)
				counter[s[j]-'a']++;
		}
		int ans = counter['c'-'a']/2;
		ans = min(ans,counter['d'-'a']);
		ans = min(ans,counter['e'-'a']/2);
		ans = min(ans,counter['f'-'a']);
		ans = min(ans,counter['h'-'a']);
		ans = min(ans,counter['o'-'a']);
		cout << ans << "\n";
	}
}
