#include<iostream>

using namespace std;

long long int gcd(long long int a,long long int b)
{
	if(b==0)
		return a;
	else return gcd(b,a%b);
}

struct realnum{
	long long int x,y;
	realnum(long long int a, long long int b)
	{
		x = a;
		y = b;
	}
};

realnum addp(realnum a, realnum b)
{
	long long int num = a.x*b.y+b.x*a.y;
	long long int den = 2*a.y*b.y;
	long long int f = gcd(num,den);
	num/=f;
	den/=f;
	return realnum(num,den);
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		if(n==1)
		{
			cout << 1 << " " << 2 << " ";
		}
		else if(n==2)
		{
			cout << 1 << " " << 4 << " ";
		}
		else
		{
			realnum a(1,2);
			realnum b(1,4);
			realnum c = addp(a,b);
			for(int i=4 ; i<=n ; i++)
			{
				a = b;
				b = c;
				c = addp(a,b);
			}
			cout << c.x << " " << c.y << " ";
		}
	}
}
