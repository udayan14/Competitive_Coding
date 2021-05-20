// Code for the modular struct copied from 
// https://github.com/e-maxx-eng/e-maxx-eng-aux/blob/master/src/polynomial.cpp

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


const long long int p = 998244353;

template<int m>
struct modular {
	int64_t r;
	modular() : r(0) {}
	modular(int64_t rr) : r(rr) {if(abs(r) >= m) r %= m; if(r < 0) r += m;}
	modular inv() const {return bpow(*this, m - 2);}
	modular operator * (const modular &t) const {return (r * t.r) % m;}
	modular operator / (const modular &t) const {return *this * t.inv();}
	modular operator += (const modular &t) {r += t.r; if(r >= m) r -= m; return *this;}
	modular operator -= (const modular &t) {r -= t.r; if(r < 0) r += m; return *this;}
	modular operator + (const modular &t) const {return modular(*this) += t;}
	modular operator - (const modular &t) const {return modular(*this) -= t;}
	modular operator *= (const modular &t) {return *this = *this * t;}
	modular operator /= (const modular &t) {return *this = *this / t;}
	
	bool operator == (const modular &t) const {return r == t.r;}
	bool operator != (const modular &t) const {return r != t.r;}
	
	operator int64_t() const {return r;}
};

typedef modular<p> base;

ll bin_exp(ll x, ll y){
	if(x==1) return 1;
	ll ret = 1;
	while(y){
		if(y&1) ret = (ret*x) % p;
		x = (x*x)%p;
		y >>= 1;
	}
	return ret;
}

ll mod_inv(ll n){
	return bin_exp(n,p-2);
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	t = 1;

    while(t--){
        ll m, n, k;
		cin >> m >> n >> k;
		base inv_k(mod_inv(k));
		if(k==1){
			cout << "1\n";
			continue;
		}
		else if(m==1){
			base out(1);
			base temp(1 - inv_k);

			for(int i=1 ; i<n ; i++){
				out += temp;
			}
			cout << out << "\n";
			continue;
		}
		else{
			base out = base(2) - inv_k;
			base temp;
			temp = base(2);
			temp -= base(3) * inv_k ;
			temp += inv_k * inv_k * inv_k;
			for(int i=1 ; i<n ; i++){
				out += temp;
			}
			cout << out << "\n";
			continue;
		}

    }
    return 0;
}

