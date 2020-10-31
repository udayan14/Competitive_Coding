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
        ll a,b;
		cin >> a >> b;
		if(a > b) swap(a,b);

		if(a==b){
			if(a%3==0) cout << "YES\n";
			else cout << "NO\n";
			continue;
		}
		if(2*a < b){
			cout << "NO\n";
			continue;
		}
		ll excess = b - a;
		a -= excess;
		b -= 2*excess;
		if(a%3==0){
			cout << "YES\n";
		}
		else cout << "NO\n";
    }
    return 0;
}

