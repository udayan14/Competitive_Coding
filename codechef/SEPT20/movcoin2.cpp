//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const long long int p = 1000000007;

vector<vector<int>> adj;
vector<int> c;
long long int answer = 0;
long long int xor_val = 0;

long long int mod_exp(long long int x, long long int y){
    if(x==1) return 1;
    long long int res = 1;
    while(y){
        if(y&1) res = (res*x) % p;
        x = (x*x) % p;
        y >>= 1;
    }
    return res;
}

void dfs(int node, int par, long long int depth){
    if(c[node]) xor_val ^= depth;
    for(auto child : adj[node]){
        if(child!=par)
            dfs(child,node,depth+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        adj = vector<vector<int>> (n+1);
        c = vector<int> (n+1);
        int u, v;
        for(int i=0 ; i<n-1 ; i++){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int in;
        for(int i=1 ; i<=n ; i++){
            cin >> in;
            c[i] = in&1;
        }
        answer = 0;
        for(int i=1 ; i<=n ; i++){
            xor_val = 0;
            dfs(i,i,0);
            if(xor_val==0){
                answer = (answer + mod_exp(2,i)) % p;
            }
        }

        cout << answer << "\n";
    }
    return 0;
}

