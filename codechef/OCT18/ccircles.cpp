#include<iostream>
#include<cmath>
#include<cstring>

#define M 1000005
long long int high[M];
long long int low[M];
long long int output[M];
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(high,0,sizeof(high));
	memset(low,0,sizeof(low));
	memset(output,0,sizeof(output));
	int n,q;
	cin >> n >> q;
	long long int x[n],y[n],r[n];
	for(int i=0 ; i<n ; i++)
	{
		cin >> x[i] >> y[i] >> r[i];
	}
	for(int i=0 ; i<n ; i++)
	{
		for(int j=i+1 ; j<n ; j++)
		{
			double dist = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
			double max_distf = dist + r[i] + r[j];
			long long int max_dist = floor(max_distf);
			double min_distf;
			if(dist > r[i]+r[j])
				min_distf = dist - (r[i]+r[j]);
			else if(dist < max(r[i],r[j])-min(r[i],r[j]))
				min_distf = max(r[i],r[j]) - (dist + min(r[i],r[j]));
			else
				min_distf = 0;
			long long int min_dist = ceil(min_distf);
			if(max_dist<M && max_dist>=0)
				high[max_dist]++;
			if(min_dist<M && min_dist>=0)
				low[min_dist]++;
		}
	}
	//for(int i=0 ; i<100 ; i++)
		//cout << low[i] << " " << high[i] << "\n";
	long long int count=low[0];
	output[0] = low[0];
	for(int i=1 ; i<M ; i++)
	{
		count+=low[i]-high[i-1];
		output[i] = count;
	}
	while(q--)
	{
		long long int k;
		cin >> k;
		cout << output[k] << "\n";
	}
}

