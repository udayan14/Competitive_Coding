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

inline bool isGood(ll val, ll k, vector<pair<ll,ll>> segments){
	ll count = 0;
	for(auto seg : segments){
		if(seg.first < val){
			count += min(val - seg.first, seg.second - seg.first + 1);
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
		vector<pair<ll,ll>> segments(n);
		
		ll l, r;
		for(int i=0 ; i<n ; i++){
			cin >> l >> r;
			segments[i] = {l,r};
		}

		l = -1;
		r = 1;
		
		while(!isGood(l,k,segments)) l *= 2;
		while(isGood(r,k,segments)) r <<= 1;

		while(r-l > 1){
			ll m = (l+r)/2;
			if(isGood(m,k,segments)) l = m;
			else r = m;
		}
		cout << l << "\n";
    }
    return 0;
}

