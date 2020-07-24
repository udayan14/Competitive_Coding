#include <iostream>
using namespace std;

int twice_square[750];
int prime_arr[50000];
int limit;

void init1()
{
	for (int i = 0; i < 750; ++i)
	{
		twice_square[i] = 2 * i * i;
	}
}

int SieveOfEratosthenes(int n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n+1];
    prime[0] = false;
    prime[1] = false;
    int i=0;
    memset(prime, true, sizeof(prime)); 
    for (int p=2; p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {

            prime_arr[i]=p;
            i++;
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
    return i;
}


int count_ways(int n)
{
    int out = 0;
    int i=1;
    int j=limit-1;
    while(i<750 && j>=0)
    {
        int sum = prime_arr[j] + twice_square[i];
        if(sum > n)
            j--;
        else if(sum < n)
            i++;
        else
        {
            out++;
            i++;
        }
    }
    return out;
}

int main(){

init1();
limit = SieveOfEratosthenes(500000);
int t;
cin >> t;
while(t--){
	int n;
	cin >> n;
    cout << count_ways(n) << endl;
}

}