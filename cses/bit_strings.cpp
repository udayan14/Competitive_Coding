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

long long int mod_exp(ll x, ll y){
	if(x==1) return 1;
	else if(x==0) return 0;
	ll res = 1;
	while(y){
		if(y&1) res = (res*x) % p;
		x = (x*x) % p;
		y >>= 1;
	}
	return res;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	t = 1;

    while(t--){
        ll n;
		cin >> n;
		cout << mod_exp(2,n) << "\n";
    }
    return 0;
}

