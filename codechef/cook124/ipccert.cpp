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
        int n, m, k;
		cin >> n >> m >> k;
		vector<int> q(n);
		vector<vector<int>> T(n,vector<int>(k,0));
		int out = 0;
		for(int i=0 ; i<n ; i++){
			ll tot_time = 0;
			for(int j=0 ; j<k ; j++){
				ll in;
				cin >> in;
				tot_time += in;
			}
			ll q;
			cin >> q;
			if(tot_time < m || q>10) continue;
			out++;
		}
		cout << out << "\n";
    }
    return 0;
}

