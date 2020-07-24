#include<iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int N,a,b;
		cin >> N >> a >> b;
		int bob = 0;
		int alice = 0;
		int common = 0;
		for(int i=0 ; i<N ; i++)
		{
			int in;
			cin >> in;
			if(in%a==0 && in%b==0)
				common++;
			else if(in%a==0)
				bob++;
			else if(in%b==0)
				alice++;
		}
		if(common>0)
			bob++;
		if(bob>alice)
			cout << "BOB\n";
		else
			cout << "ALICE\n";
	}
}
