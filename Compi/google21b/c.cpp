#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
#include<cstring>
using namespace std;

int nmax = 60000000;
vector<long long> primes(nmax,0);

int counter = 0;

void simpleSieve(int limit, vector<int> &prime)
{
    // Create a boolean array "mark[0..n-1]" and initialize
    // all entries of it as true. A value in mark[p] will
    // finally be false if 'p' is Not a prime, else true.
    vector<bool> mark(limit + 1, true);
 
    for (int p=2; p*p<limit; p++)
    {
        // If p is not changed, then it is a prime
        if (mark[p] == true)
        {
            // Update all multiples of p
            for (int i=p*p; i<limit; i+=p)
                mark[i] = false;
        }
    }
 
    // Print all prime numbers and store them in prime
    for (int p=2; p<limit; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p);
			primes[counter++] = p;
            //cout << p << " ";
        }
    }
}
 
// Prints all prime numbers smaller than 'n'
void segmentedSieve(int n)
{
    // Compute all primes smaller than or equal
    // to square root of n using simple sieve
    int limit = floor(sqrt(n))+1;
    vector<int> prime;
    prime.reserve(limit);
    simpleSieve(limit, prime);
 
    // Divide the range [0..n-1] in different segments
    // We have chosen segment size as sqrt(n).
    int low = limit;
    int high = 2*limit;
 
    // While all segments of range [0..n-1] are not processed,
    // process one segment at a time
    while (low < n)
    {
        if (high >= n)
           high = n;
         
        // To mark primes in current range. A value in mark[i]
        // will finally be false if 'i-low' is Not a prime,
        // else true.
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
 
        // Use the found primes by simpleSieve() to find
        // primes in current range
        for (int i = 0; i < prime.size(); i++)
        {
            // Find the minimum number in [low..high] that is
            // a multiple of prime[i] (divisible by prime[i])
            // For example, if low is 31 and prime[i] is 3,
            // we start with 33.
            int loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
 
            /* Mark multiples of prime[i] in [low..high]:
                We are marking j - low for j, i.e. each number
                in range [low, high] is mapped to [0, high-low]
                so if range is [50, 100] marking 50 corresponds
                to marking 0, marking 51 corresponds to 1 and
                so on. In this way we need to allocate space only
                for range */
            for (int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }
 
        // Numbers which are not marked as false are prime
        for (int i = low; i<high; i++)
            if (mark[i - low] == true)
				primes[counter++] = i;
                //cout << i << " ";
 
        // Update low and high for next segment
        low = low + limit;
        high = high + limit;
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	segmentedSieve(1000000010);
    int t;
    cin >> t;
    for(int cas = 1 ; cas<=t ; cas++){
		long long out = 0;
		long long z;
		cin >> z;

		if(z==6) out = z;
		else{
			long long l = 0;
			long long r = counter-1;

			while(r - l > 1){
				long long m = (l + r) / 2;
				if(primes[m] * primes[m+1] <= z) l = m;
				else r = m;
			}
			out = primes[l] * primes[l+1];
		}
        cout << "Case #" << cas << ": " << out << "\n";
    }
}
