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
        int n, m;
		cin >> n >> m;
		vector<short> t(n);
		vector<ll> x(n);
		vector<int> y(n);

		for(int i=0 ; i<n ; i++){
			cin >> t[i] >> x[i] >> y[i];
		}

		vector<int> bananas(m+1,-1);

		bananas[0] = 0;
		queue<pair<int,int>> q;
		q.push({0,0});

		while(!q.empty()){
			auto curr = q.front();
			q.pop();
			ll num_banana = curr.first;
			int time = curr.second;
			if(time>=n) continue;

			double x_val = x[time] / 100000.0;

			if(t[time]==1){
				for(int i=0 ; i< y[time] && num_banana <= m ; i++){
					num_banana = (ll)ceil(num_banana + x_val);
					if(bananas[num_banana]==-1){
						bananas[num_banana] = time + 1;
						q.push({num_banana,time+1});
					}
				}
			}
			else{
				for(int i=0 ; i< y[time] && num_banana <= m ; i++){
					num_banana = (ll)ceil(num_banana * x_val);
					if(bananas[num_banana]==-1){
						bananas[num_banana] = time + 1;
						q.push({num_banana,time+1});
					}
				}

			}
		}
		for(int i=1 ; i<=m ; i++){
			cout << bananas[i] << "\n";
		}
    }
    return 0;
}

