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
ll nb, ns, nc;
ll pb, ps, pc;
ll req_b(0), req_s(0), req_c(0);
ll roubles;

inline bool isGood(ll burgers){
	//cout << burgers << "*\n";
	ll buy_b = burgers*req_b - nb;
	ll buy_s = burgers*req_s - ns;
	ll buy_c = burgers*req_c - nc;
	amax(buy_b,0);
	amax(buy_s,0);
	amax(buy_c,0);
	
	ll total_cost = buy_b*pb + buy_s*ps + buy_c*pc;
	if(total_cost > roubles) return false;
	else return true;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	t = 1;

    while(t--){
        string s;
		cin >> s;
		cin >> nb >> ns >> nc;
		cin >> pb >> ps >> pc;
		cin >> roubles;

		for(auto c : s){
			if(c == 'B') req_b++;
			else if(c == 'S') req_s++;
			else if(c == 'C') req_c++;
		}

		//cout << req_b << " " << req_s << " " << req_c << "\n";
		ll l = 0;
		ll r = 1;
		while(isGood(r)){
			r <<= 1;
		}

		while(r-l > 1){
			ll m = (l+r)/2;
			if(isGood(m)) l = m;
			else r = m;
		}
		cout << l << "\n";
    }
    return 0;
}

