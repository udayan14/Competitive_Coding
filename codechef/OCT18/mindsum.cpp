#include <iostream>
#include <queue>
using namespace std;

long long int digitsum(long long int n)
{
	int out = 0;
	while(n!=0){
	out+=(n%10);
	n/=10;
	}
	return out;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long int n,d;
		cin >> n >> d;
		int target;
		if((d%9)==3 || (d%9)==6)
			target = 3;
		else if((d%9)==0)
			target = 9;
		else
			target = 1;
		if(target==3)
		{
			target = n%3;
			if(target==0) target=3;
		}
		else if(target==6)
		{
			target = n%3;
			if(target==0) target=3;
		}
		else if(target==9)
		{
			target = n%9;
			if (target==0) target=9;
		}
		queue <pair <long long int, int> > q;
		q.push(make_pair(n,0));
		while(q.front().first!=target)
		{
			long long int temp1 = q.front().first;
			int temp2 = q.front().second;
			q.pop();
			q.push(make_pair(digitsum(temp1),temp2+1));
			q.push(make_pair(temp1+d,temp2+1));
		}
		cout << q.front().first << " " << q.front().second << "\n";
	}
}
