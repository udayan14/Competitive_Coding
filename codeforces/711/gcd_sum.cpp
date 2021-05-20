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

ll gcd_sum(ll n){
	ll temp = n;
	ll digit_sum = 0;
	while(temp){
		digit_sum += temp%10;
		temp /= 10;
	}

	return __gcd(n,digit_sum);
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
	//cout << gcd_sum(75) << "\n";
    int t;
    cin >> t;

    while(t--){
        ll n;
		cin >> n;
		for(ll x = n; ; x++){
			if(gcd_sum(x)>1){
				cout << x << "\n";
				break;
			}
		}
		
    }
    return 0;
}

