#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long int m,n;
	cin >> n >> m;
	long long int A[n],B[n];
	priority_queue< pair<long long int,int> > v;
	long long int total_ballons = 0;
	for(int i=0 ; i<n ; i++)
	{
		cin >> A[i];
	}
	for(int i=0 ; i<n ; i++)
	{
		cin >> B[i];
		if(A[i]==0 || B[i]==0)
			continue;
		v.push(make_pair(A[i]*B[i],i));
		total_ballons+=A[i];
	}	
	if(total_ballons<=m)
	{
	cout << 0 << "\n";
	return 0;
	}
	/*sort_heap(v.begin(),v.end());*/
	//for(int i=0 ; i<v.size() ; i++)
		/*cout << v[i].first << " " << v[i].second << "\n";*/
	while(v.size()>0 && m>0)
	{
		long long int val = v.top().first;
		int i = v.top().second;
		v.pop();
		if(v.size()==0)
		{
			if(A[i]<=m)
			{
				m-=A[i];
				cout << "0\n";
				return 0;
			}
			else
			{
				cout << (A[i]-m)*B[i] << "\n";
				return 0;
			}
		}
		else
		{
			long long int val1 = v.top().first;
			int num_ballons = (val-val1)/B[i] + 1;
			if(num_ballons>m)
			{
				v.push(make_pair(val - B[i]*m,i));
				m=0;
			}
			else
			{
				long long rem = val - B[i]*num_ballons;
				if(rem==0)
				{
					m-=num_ballons;
					//cout << "Taking " << num_ballons << " balloons from index. All balloons given " << i << "\n";
				}
				else
				{
					v.push(make_pair(rem,i));
					m-=num_ballons;
					//cout << "Taking " << num_ballons << " balloons from index " << i << "\n";

				}
			}
		}
	}
	if(v.size()==0)
		cout << 0 << "\n";
	else cout << v.top().first << "\n";

}
