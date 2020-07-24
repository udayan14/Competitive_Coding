#include<iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long int n,k;
		cin >> n >> k;
		long long int a[n];
		for(int i=0 ; i<n ; i++)
		{
			cin >> a[i];
		}
		long long int sum = 0;
		long long int max_sum = 0;
		int count = 0;
		int max_count = 0;
		//a variation of kadane's algorithm
		for(int i=0 ; i<n ; i++)
		{
			if(sum+a[i]<=k)
			{
				sum+=a[i];
				count++;
			}
			else
			{
			
				while(sum+a[i]>k && sum!=0)
				{
					sum-=a[i-count];
					count--;
				}
				sum+=a[i];
				count++;
			}
			if(count>=max_count)
			{
				max_sum=sum;
				max_count = count;
			}
		}
		long long int rem = k - max_sum;
		cout << max_count << " " << rem << "\n";
	}
}
