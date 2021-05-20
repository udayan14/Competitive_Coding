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

inline bool isGood(const vector<int> &v, int num_pieces, double len){
	ll count = 0;
	for(auto rope_len : v){
		count += floor((1.0*(double)rope_len)/len);
	}
	if(count >= num_pieces) return true;
	else return false;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	t = 1;

    while(t--){
        int n,k;
		cin >> n >> k;
		vector<int> a(n);
		for(int i=0 ; i<n ; i++) cin >> a[i];
		cout.precision(10);
		double l = 0.0;
		double r = 1.0;
		while(isGood(a,k,r)){
			r *= 2.0;
		}
		for(int i=0 ; i<100 ; i++){
			double m = (l+r)/2;
			if(isGood(a,k,m)) l = m;
			else r = m;
		}
		cout << l << "\n";
    }
    return 0;
}

