#include <iostream>
#include <map>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		long long int even=0;
		long long int odd=0;
		map <unsigned long long int,unsigned long long int> counter;
		counter.clear();
		long long int output = 0;
		for(int i=0 ; i<n ; i++)
		{
			unsigned long long int in;
			cin >> in;
			if(in%2==0)
				even++;
			else
				odd++;
			counter[in]++;
			unsigned long long int inv = 2^in;
			if(counter.count(inv)>0)
				output-=counter[inv];
		}
		output+=(even*(even-1))/2 + (odd*(odd-1))/2;
		for(map<unsigned long long int,unsigned long long int>::iterator it=counter.begin() ; it!=counter.end() ; it++)
		{
			output-=(it->second*(it->second-1))/2;
		}
		cout << output << "\n";
	}
}
