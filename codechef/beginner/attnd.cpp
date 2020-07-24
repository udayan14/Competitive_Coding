#include<iostream>
#include<string>
#include<map>
#include<vector>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<string> a1(n);
		vector<string> a2(n);
		map<string,int> counter;
		for(int i=0 ; i<n ; i++)
		{
			string s1,s2;
			cin >> s1 >> s2;
			a1[i] = s1;
			a2[i] = s2;
			counter[s1]++;
		}
		for(int i=0 ; i<n ; i++)
		{
			if(counter[a1[i]]==1)
				cout << a1[i] << "\n";
			else
				cout << a1[i] << " " << a2[i] << "\n";
		}
	}
}
