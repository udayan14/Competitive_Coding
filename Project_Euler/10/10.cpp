#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void SieveOfEratosthenes(int n, vector <int> &primes , vector<long long int> &sum_prime)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n+1];
    prime[0] = false;
    prime[1] = false;
    memset(prime, true, sizeof(prime)); 
    for (int p=2; p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            primes.push_back(p);
            if(sum_prime.size()==0)
                sum_prime.push_back(p);
            else sum_prime.push_back(sum_prime[sum_prime.size() - 1] + primes[primes.size()-1]);
                    
            
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
}


int main(){
    
    vector <int> primes;
    vector <long long int> sum_prime;
    SieveOfEratosthenes(3000000,primes,sum_prime);
   
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        int x;
        for(int i=0 ; primes[i]<=n ; i++){
            x = i;
        }
        cout << sum_prime[x] << endl;
        
    }
    return 0;
}
