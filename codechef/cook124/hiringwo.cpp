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

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        ll k, x;
		cin >> k >> x;
		ll f1,f2;
		ll out = LLONG_MAX;
		for(ll i=1 ; i<=sqrt(x) ; i++){
			for(ll j=i ; j<=sqrt(x) ; j++){
				if(i*j == x && __gcd(i,j)==1){
					amin(out,i+j+k-2);
				}
			}
			if(x%i==0){
				ll f2 = x/i;

			}
		}
		cout << out << "\n";
	}
    return 0;
}

