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


vector<vector<int>> adj;
vector<int> output;

const long long int p = 1000000007;

void dfs(int node, int par, int cnt){
	if(cnt&1) output[node] = 1;
	else output[node] = 2;

	for(auto child : adj[node]){
		if(child!=par)
			dfs(child,node,cnt^1);
	}
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        int n;
		cin >> n;
		adj = vector<vector<int>> (n+1);
		output = vector<int> (n+1);
		int u,v;
		for(int i=0 ; i<n-1 ; i++){
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		dfs(1,1,0);

		for(int i=1 ; i<=n ; i++) cout << output[i] << " ";
		cout << "\n";
    }
    return 0;
}

