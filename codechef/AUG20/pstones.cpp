//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<vector<int>> adj;
map<pair<int,int>,int> color;
vector<int> stk;


void toposort(int node, int par){
    for(auto child : adj[node]){
        if(child!=par)
            toposort(child,node);
    }
    stk.push_back(node);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        adj = vector<vector<int>> (n+1);
        int u, v, c;
        for(int i=0 ; i<n-1 ; i++){
            cin >> u >> v >> c;
            adj[u].push_back(v);
            adj[v].push_back(u);
            color[make_pair(u,v)] = c; 
            color[make_pair(v,u)] = c; 
        }

        int start = -1;
        for(int i=1 ; i<=n ; i++){
            if(adj[i].size()==1){
                start = i;
                break;
            }
        }
        stk.clear();
        toposort(start,start);
        
        vector<int> color_vec;
        for(int i=1 ; i<stk.size() ; i++){
            color_vec.push_back(color[make_pair(stk[i-1],stk[i])]);
        }
        vector<vector<short>> dp(n+1,vector<short>(1<<k,0));
        for(int i=0 ; i<color_vec.size() ; i++){
            for(int j=i ; j<color_vec.size() ; j++){
                if(i==j){
                    long long int bit_mask = (1 << (color_vec[i] - 1));
                    dp[i+1][bit_mask] = 1;
                    dp[n-1-i][bit_mask] = 1;
                }
                long long int bit_mask = (1<<(color_vec[i]-1)) | (1<<(color_vec[j]-1));
                dp[j-i][bit_mask] = 1;
            }
        }
        dp[n][0] = 1;
        for(int i=1 ; i<=n ; i++){
            for(auto ele : dp[i]) cout << ele;
            cout << "\n";
        }
    }
    return 0;
}

