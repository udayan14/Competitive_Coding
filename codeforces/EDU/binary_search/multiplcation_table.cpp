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


const long long int p = 1000000007;

inline bool isGood(ll val, ll k, ll n){
	ll count = 0;
	for(int i=1 ; i<=n ; i++){
		if(i < val){
			ll temp = val / i;
			if(val%i==0)  temp--;
			count += min(temp, n);
		}
	}
	
	return count <= k;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	t = 1;

    while(t--){
        ll n, k;
		cin >> n >> k;
		k--;
		ll l, r;
		l = 0;
		r = 1;
		
		while(isGood(r,k,n)) r <<= 1;

		while(r-l > 1){
			ll m = (l+r)/2;
			if(isGood(m,k,n)) l = m;
			else r = m;
		}
		cout << l << "\n";
    }
    return 0;
}

