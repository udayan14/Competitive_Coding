#include<iostream>

using namespace std;

int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int h1,w1;
		cin >> h1 >> w1;
		char p1[h1][w1];
		for(int i=0 ; i<h1 ; i++)
			for(int j=0 ; j<w1 ; j++)
			{
				char c;
				cin >> c;
				p1[i][j] = c;
			}
		int h2,w2;
		cin >> h2 >> w2;
		char p2[h2][w2];
		for(int i=0 ; i<h2 ; i++)
			for(int j=0 ; j<w2 ; j++)
			{
				char c;
				cin >> c;
				p2[i][j] = c;
			}
		int gcd_h = gcd(h1,h2);
		int gcd_w = gcd(w1,w2);
		long long int p1_hscale = h2/gcd_h;
		long long int p1_wscale = w2/gcd_w;
		long long int p2_hscale = h1/gcd_h;
		long long int p2_wscale = w1/gcd_w;
		unsigned long long int out = 0;
		for(long long int i=0 ; i<h1*p1_hscale ; i++)
			for(long long int j=0 ; j<w1*p1_wscale ; j++)
			{
				if(p1[i/p1_hscale][j/p1_wscale]==p2[i/p2_hscale][j/p2_wscale])
					out++;
			}
	cout << out << "\n";
	}
}
