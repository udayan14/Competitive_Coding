#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define Kmax 1002
#define m 1000000009
int Choose[Kmax][Kmax];
int Stirling[Kmax][Kmax];
int factorial[Kmax];
int modexp(long long int x, long long int y, long long int p)
{
    long long int out = 1;
    x = x % p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            out = ((out%p)*(x%p)) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = ((x%p)*(x%p)) % p;  
    }
    return out;
}

int modinv(int a){               //m is prime
	return modexp(a,m-2,m);
}

void init1(){
	memset(Choose,0,sizeof(Choose));
	for(int i=0 ; i<Kmax ; i++)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (j==0 || j==i)
			{
				Choose[i][j] = 1;
			}else
			{
				Choose[i][j] = ((Choose[i-1][j]%m) + (Choose[i-1][j-1]%m))%m;
			}
		}
	}	
}
void init2(){
	memset(Stirling,0,sizeof(Stirling));
	for(int i=1 ; i<Kmax ; i++)
	{
		for (int j = 1; j <= i; ++j)
		{
			if (j==1 || j==i)
			{
				Stirling[i][j] = 1;
			}else
			{
				Stirling[i][j] = ((Stirling[i-1][j-1]%m) + ((j%m) * (Stirling[i-1][j]%m))%m)%m;
			}
		}
	}	
}

void init3(){
	factorial[0] = 1;
	for (int i = 1; i < Kmax; ++i)
	{
		factorial[i] = ((i%m)*(factorial[i-1]%m))%m;
	}
}

int solve(long long int n, int k){
	long long int sum = 0;
	long long int c = ((n%m * (n+1)%m)%m * modinv(2))%m;
	for (int i = 1; i < k+1; ++i)
	{
		sum = (sum + (((factorial[i] * Stirling[k][i])%m)*c)%m)%m;
		c = (((c * (n-i)%m)%m) * modinv(i+2))%m;
	}
	return ((sum - 1)%m + m)%m;
}

int main() {


init2();
init3();
int q;
cin >> q;
while(q--){
	int k;
	long long int n;
	cin >> n >> k;
	if(n<3)
		cout << 0 << endl;
	else
		cout << solve(n-1,k) << endl;
}

}
