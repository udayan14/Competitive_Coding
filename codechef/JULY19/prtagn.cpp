#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int q;
		cin >> q;
		unordered_set<int> s;
		s.clear();
		unordered_set<int> :: iterator itr;
		long long int odd = 0;
		long long int even = 0;
		while(q--)
		{
			int x;
			cin >> x;
			if(s.find(x)==s.end())
			{
				if(__builtin_popcount(x)%2==0)
				{
					even += even;
					odd += odd;
					even++;
				}
				else
				{
					even += odd;
					odd = even;
					odd++;
				}
				unordered_set<int> temp;
				temp.clear();
				for(itr = s.begin() ; itr != s.end() ; itr++)
				{
					int val = *itr;
					temp.insert(val^x);
				}
				for(itr = temp.begin() ; itr != temp.end() ; itr++)
				{
					s.insert(*itr);
				}
				s.insert(x);
			}
			cout << even << " " << odd << "\n";
		}
	}
}
