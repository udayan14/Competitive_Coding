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

inline bool isGood(int opt_dist, int num_cows, const vector<int> &pos){
	int prev_pos = pos[0];
	int placed = 1;
	int n = pos.size();
	for(int i=1 ; i<n ; i++){
		if(pos[i] - prev_pos >= opt_dist){
			prev_pos = pos[i];
			placed++;
		}
	}
	return placed >= num_cows;
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	t = 1;

    while(t--){
        int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for(int i=0 ; i<n ; i++) cin >> a[i];

		int l = 0;
		int r = a[n-1] - a[0] + 1;

		while(r-l > 1){
			int m = (l+r)/2;
			if(isGood(m,k,a)){
				l = m;
			}
			else r = m;
		}
		cout << l << "\n";
    }
    return 0;
}

