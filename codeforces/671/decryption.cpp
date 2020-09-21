#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

template<typename T, typename U> 
static inline void amin(T &x, U y) 
{ 
    if (y < x) 
        x = y; 
} 
  
// call by reference is used in x 
template<typename T, typename U> 
static inline void amax(T &x, U y) 
{ 
    if (x < y) 
        x = y; 
}

ll n_max = 200000 + 1;
vector<ll> primes;
vector<short> is_prime(n_max,1);


void sieve_of_eratosthenes(){
	is_prime[0] = 0;
	is_prime[1] = 0;
	for(int i=2 ; i<n_max ; i++){
		if(is_prime[i]){
			primes.push_back(i);
			for(int j = 2*i ; j<n_max ; j+=i){
				is_prime[i] = 0;
			}
		}
	}
}

const long long int p = 1000000007;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
	sieve_of_eratosthenes();

    while(t--){
        ll n;
		cin >> n;
		vector<pair<ll,ll>> prime_divisors;
		for(auto p : primes){
			if(n==1) break;
			ll temp = 0;
			while(n%p==0){
				n /= p;
				temp++;
			}
			if(temp) prime_divisors.push_back({p,temp});
		}
		if(n > 1) prime_divisors.push_back({n,1});

		int sz = prime_divisors.size();
		vector<vector<ll>> output(sz);
		vector<ll> curr;
		int i = 0;
		for(auto pr : prime_divisors){
			vector<ll> build;
			ll p = pr.first;
			ll count = pr.second;
			ll temp = p;
			for(int i=0 ; i<count ; i++){
				build.push_back(temp);
				for(auto c : curr){
					build.push_back(temp*c);
				}
				temp *= p;
			}
			curr.insert(curr.end(),build.begin(),build.end());
			reverse(build.begin(),build.end());
			if(i==sz-1){
				
			reverse(build.begin()+1,build.end());
			reverse(build.begin(),build.end());
			}
			output[i++] = build;
		}
		
		for(auto v : output){
			for(auto fctr : v){
				cout << fctr << " ";
			}
		}
		cout << "\n";

		
		if(sz==2 && prime_divisors[0].second==1 && prime_divisors[1].second==1){
			cout << "1\n";
		}
		else{
			cout << "0\n";
		}

			}
}

