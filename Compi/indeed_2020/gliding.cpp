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

struct Treasure{
	int x,y,v;
};

vector<int> dp;
vector<vector<int>> adj;
vector<Treasure> loc;

int get(int n){
	if(dp[n] != -1) return dp[n];
	int out = INT_MIN;
	if(adj[n].size()==0){
		dp[n] = loc[n].v;
		return dp[n];
	}
	for(auto node : adj[n]){
		amax(out,get(node));
	}
	dp[n] = out + loc[n].v;
	return dp[n];

}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
	t = 1;

    while(t--){
        int n, r;
		cin >> n >> r;
		loc = vector<Treasure> (n,{0,0,0});
		dp = vector<int> (n,-1);
		int x, y, v;
		for(int i=0 ; i<n ; i++){
			cin >> x >> y >> v;
			loc[i] = {x,y,v};
		}
		adj = vector<vector<int>> (n);
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				if(i==j) continue;
				if(r * (loc[i].y-loc[j].y) >= abs(loc[i].x-loc[j].x))
					adj[i].push_back(j);
			}
		}
		int output = INT_MIN;
		for(int i=0 ; i<n ; i++){
			amax(output,get(i));
		}
		cout << output << "\n";
    }
    return 0;
}

