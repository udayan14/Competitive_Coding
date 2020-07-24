#include<iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		long long int a[n];
		long long int sum = 0;
		double avg;
		for(int i=0 ; i<n ; i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		avg = sum/double(n);
		//cout << avg << "\n";
		bool flag = false;
		for(int i=0 ; i<n ; i++)
		{
			if(a[i]==avg)
			{
				cout << i+1 << "\n";
				flag = true;
				break;
			}
		}
		if(!flag)
			cout << "Impossible\n";
	}
}
