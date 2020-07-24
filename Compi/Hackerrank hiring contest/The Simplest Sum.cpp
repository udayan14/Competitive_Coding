#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	long long int m = 1000000007;
	long long int lim = 1e18;
	int q;
	cin >> q;
	while(q--)
	{
		int k,a,b;
		cin >> k >> a >> b;
		unsigned long long int lim_arr[1000];
		unsigned long long int sum_arr[1000];
		lim_arr[0] = 0;
		sum_arr[0] = 0;
		int i=0;
		while(lim_arr[i] <= lim)
		{
			lim_arr[i+1] = k*lim_arr[i] + 1;
			sum_arr[i+1] = (sum_arr[i] + lim_arr[i+1]%m)%m;
			i++;
		}
		unsigned long long int prev = a;
		long long int out = 0;
		int first_index = 0;
		int last_index = 0;
		for (int j = 1; j <= i; ++j)
		{
			if(a < lim_arr[j])
			{
				first_index = j;
				break;
			}			
		}
		out = (out + ((lim_arr[first_index] - a)%m*sum_arr[first_index-1])%m)%m;
		prev = lim_arr[first_index];
		for(int j=first_index ; lim_arr[j]<=b ; j++)
		{
			out = (out + ((lim_arr[j] - prev)%m * sum_arr[j-1])%m)%m;
			prev = lim_arr[j];
			last_index = j;
		}
		out = (out + ((b - lim_arr[last_index] + 1)%m * sum_arr[last_index])%m)%m;

		if(lim_arr[first_index]>b)
			out = ((b-a+1)%m * sum_arr[first_index-1])%m;
		cout << out << endl;
	}


}