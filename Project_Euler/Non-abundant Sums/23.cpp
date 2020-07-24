#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void SieveOfEratosthenes(int n, vector <int> &primes)
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
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
}

///*** Calculates sum of all divisors***///
int sum_of_divisors(int n,vector <int> primes){
	int out = 1;
	int len = primes.size();
	for(int i=0 ; i<len ; i++){
		if (n==1) break;
		int k = 1;
		int sum_of_pow = 1;
		while(n%primes[i]==0){
			n /= primes[i];
			k *= primes[i];
			sum_of_pow += k;		
		}
		out *= sum_of_pow;
	}
	return out;
}

void FindAbundant(int n, vector<int> &v,vector<int>primes){
	for(int i=1; i<=n; i++){
		if(sum_of_divisors(i,primes)>2*i)
			v.push_back(i);
	}
}

bool sum_of_two(int n, vector<int>v){
	int i=0;
	int j=v.size()-1;
	while(i!=j){
		int sum = v[i] + v[j];
		if(n==sum)
			return true;
		else if(n>sum)
			i++;
		else
			j--;
	}
	if(n == 2*v[i]) return true;
	return false;
}

int main() {
	vector <int> primes;
	vector <int> abundant;
    SieveOfEratosthenes(100000,primes); 
    FindAbundant(100000,abundant,primes);
    // int t;
    // cin >> t;
    // for(int a0=0; a0<t; a0++){
    // 	int n;
    // 	cin >> n;
    // 	if(sum_of_two(n,abundant))
    // 		cout<<"YES"<<endl;
    // 	else
    // 		cout<<"NO"<<endl;
    // }
    int ans = 0;
    for(int i=1; i<28124; i++){
    	if(!sum_of_two(i,abundant))
    		ans+=i;
    }
    cout << ans << endl;
    return 0;
}
