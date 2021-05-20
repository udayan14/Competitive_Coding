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

inline bool isGood(ll opt_val, int k, const vector<ll> &a){
	int num_blocks = 0;
	ll curr_sum = 0;
	for(auto val : a){
		if(val > opt_val) return false;
		if(curr_sum + val <= opt_val) curr_sum += val;
		else{
			num_blocks++;
			curr_sum = val;
		}
	}
	if(curr_sum>0) num_blocks++;
	return num_blocks <= k;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	t = 1;

    while(t--){
        int n, k;
		cin >> n >> k;
		vector<ll> a(n);
		ll total_sum = 0;
		for(int i=0 ; i<n ; i++) {
			cin >> a[i];
			total_sum += a[i];
		}

		ll l = 0;
		ll r = total_sum;

		while(r-l > 1){
			ll m = (l+r)/2;
			if(isGood(m,k,a)) r = m;
			else l = m;
		}
		cout << r << "\n";
    }
    return 0;
}

