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

inline bool isGood(ll val, ll k, ll n, const vector<ll> &a, const vector<ll> &b){
	ll count = 0;
	for(auto a_val : a){
		ll temp = val - a_val;
		if(b[0] < temp){
			if(temp > b[n-1]) count += n;
			else{
				int l = 0;
				int r = n-1;
				while(r-l > 1){
					int m = (l+r)/2;
					if(temp > b[m]) l = m;
					else r = m;
				}
				count += r;
			}
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
		vector<ll> a(n);
		vector<ll> b(n);
		for(int i=0 ; i<n ; i++) cin >> a[i];
		for(int i=0 ; i<n ; i++) cin >> b[i];

		sort(a.begin(),a.end());
		sort(b.begin(),b.end());

		ll l, r;
		l = 0;
		r = 1;
		
		while(isGood(r,k,n,a,b)) r <<= 1;

		while(r-l > 1){
			ll m = (l+r)/2;
			if(isGood(m,k,n,a,b)) l = m;
			else r = m;
		}
		cout << l << "\n";
    }
    return 0;
}

