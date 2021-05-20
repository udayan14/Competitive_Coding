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

bool isGood(ll num_councils, int k, int n, const vector<ll> &groups){
	ll count = 0;
	for( auto group_sz : groups){
		count += min(num_councils, group_sz);
	}

	return count >= k * num_councils;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	t = 1;

    while(t--){
        int k, n;
		cin >> k >> n;
		vector<ll> a(n);
		for(int i=0 ; i<n ; i++) cin >> a[i];

		ll l = 0;
		ll r = 1;

		while(isGood(r,k,n,a)) r <<= 1;

		while(r-l > 1){
			ll mid = (l+r)/2;
			if(isGood(mid,k,n,a)) l = mid;
			else r = mid;
		}

		cout << l << "\n";
    }
    return 0;
}

