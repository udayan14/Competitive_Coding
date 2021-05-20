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
	t = 1;

    while(t--){
        int n,m,k;
		cin >> n >> m >> k;
		vector<ll> spec(n);
		for(int i=0 ; i<n ; i++) cin >> spec[i];

		vector<ll> apartments(m);
		for(int i=0 ; i<m ; i++) cin >> apartments[i];
		
		sort(spec.begin(),spec.end());
		sort(apartments.begin(),apartments.end());

		vector<bool> isFree(apartments.size(),true);
		int out = 0;
		int prev = -1;

		for(auto sz: spec){
			auto itr = lower_bound(apartments.begin(),apartments.end(),sz-k);
			int idx = distance(apartments.begin(),itr);
			amax(idx,prev);
			while(idx < m){
				if(apartments[idx] > sz+k) break;
				if(isFree[idx]){
					isFree[idx] = false;
					prev = idx;
					out++;
					break;
				}
				idx++;
			}
		}
		
		cout << out << "\n";

    }
    return 0;
}

