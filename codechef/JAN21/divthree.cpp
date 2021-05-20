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
        long long n, k, d;
		cin >> n >> k >> d;
		vector<int> a(n);
		for(int i=0 ; i<n ; i++) cin >> a[i];

		long long total = 0;
		for(auto e : a) total += e;

		ll out = total / k;
		cout << min(out,d) << "\n";
    }
    return 0;
}

