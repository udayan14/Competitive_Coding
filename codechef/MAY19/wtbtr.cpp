#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>

using namespace std;

bool sortbysec(const pair<long long int,long long int> &a, 
              const pair<long long int,long long int> &b) 
{ 
    return (a.second < b.second); 
} 

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		pair <long long int,long long int> points[n];
		for(int i=0 ; i<n ; i++)
		{
			long long int x,y;
			cin >> x >> y;
			points[i] = make_pair(x-y,x+y);
		}
		sort(points,points+n);
		long long int curr_min = INT_MAX;
		for(int i=1 ; i<n ; i++)
		{
			curr_min = min(curr_min,points[i].first - points[i-1].first);
		}
		sort(points,points+n,sortbysec);
		for(int i=1 ; i<n ; i++)
		{
			curr_min = min(curr_min,points[i].second - points[i-1].second);
		}
		cout << double(curr_min)/2.0 << "\n";
	}
}
