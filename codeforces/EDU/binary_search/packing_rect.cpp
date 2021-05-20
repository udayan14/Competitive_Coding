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

bool isGood(ll side, ll height, ll width, ll count){
	return (side/height)*(side/width) >= count;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	t = 1;

    while(t--){
        ll w,h,n;
		cin >> w >> h >> n;
		ll l = 0;
		ll r = 1;
		while(!isGood(r,h,w,n)){
			r <<= 1;
		}
		while(r-l>1){
			ll m = (r+l)/2;
			if(isGood(m,h,w,n)) r = m;
			else l = m;
		}
		cout << r << "\n";
    }
    return 0;
}

