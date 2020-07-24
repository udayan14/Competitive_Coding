#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		unsigned long long int a[n];
		unsigned long long int a2[n];
		for(int i=0 ; i<n ; i++)
		{
			unsigned long long int in;
			cin >> in;
			a[i] = in;
			a2[i] = in*in;
		}
		map<unsigned long long int, int> counter;
		for(int i=0 ; i<n ; i++)
		{
			for(int j=0 ; j<n ; j++)
			{
				counter[a2[i]+a2[j]]++;
			}
		}
		int count = 0;
		for(int i=0 ; i<n ; i++)
		{
			for(int j=0 ; j<n ; j++)
			{
				map<unsigned long long int, int>::iterator it;
				it = counter.find(a2[i]+a[j]);
				if(it!=counter.end())
					count+=it->second;
			}
		}
		cout << count << "\n";
	}
}

