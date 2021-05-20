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
        int n, m;
		cin >> n >> m;
		long long sum_a(0), sum_b(0);
		vector<ll> a(n), b(m);
		for(int i=0 ; i<n ; i++){
			cin >> a[i];
			sum_a += a[i];
		}
		for(int i=0 ; i<m ; i++){
			cin >> b[i];
			sum_b += b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int out = 0;
		int it1 = 0;
		int it2 = m-1;
		ll delta = sum_b - sum_a;
		while(delta >= 0 && it1 < n && it2 >= 0){
			int max_step = b[it2] - a[it1];
			if(max_step <= 0) break;
			delta -= 2 * max_step;
			it1++;
			it2--;
			out++;
		}

		if(delta < 0) cout << out << "\n";
		else cout << "-1\n";
    }
    return 0;
}

