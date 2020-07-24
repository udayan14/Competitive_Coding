#include<iostream>
#include<cstring>
# define N 101
using namespace std;



bool prime[N];

void SieveOfEratosthenes()
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    memset(prime, true, sizeof(prime)); 
    prime[0] = false;
    prime[1] = false;
    for (int p=2; p<N; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<N; i += p)
                prime[i] = false;
        }
    }
}


int main()
{
	SieveOfEratosthenes();
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int arr[n];
		for(int i=0 ; i<n ; i++){
			int in;
			cin >> in;
			arr[i] = in;
		}
		bool has_one = false;
		int primes = 1000;
		for(int i=0 ; i<n ; i++){
			if(arr[i]==1)
				has_one = true;
			if(prime[arr[i]] && arr[i]<primes)
			{
				//cout<<arr[i]<<" ";
				primes = arr[i];
			}
						
		}
		if(primes==1000 || !has_one)
			cout << -1 << "\n";
		else cout << primes << "\n";
	}
}
