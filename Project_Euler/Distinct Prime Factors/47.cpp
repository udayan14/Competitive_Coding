#include <iostream>
#include <cstring>
using namespace std;
int imp_arr[2000005];
void SieveofEratosthenes(int n){
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n+1];
    prime[0] = false;
    prime[1] = false;
    memset(prime, true, sizeof(prime)); 
    memset(imp_arr,0,sizeof(imp_arr));
    for (int p=2; p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
        	imp_arr[p] = 1;
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
            {
                prime[i] = false;
            	imp_arr[i]++;
            }
        }
    }

}

int main(){

memset(imp_arr,0,sizeof(imp_arr));
SieveofEratosthenes(2000004);
int N,K;
cin >> N >> K;
bool flag;
for (int i = 2; i <= N; ++i)
{
	if (imp_arr[i]==K)
	{
		flag = true;
		for (int j = 1; j < K; ++j)
		{
			if (imp_arr[i+j]!=K)
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << i << endl;
		}
		flag = false;

	}
}
}