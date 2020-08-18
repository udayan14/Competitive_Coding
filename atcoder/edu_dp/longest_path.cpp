#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> inc;
vector<short> visited;
vector<int> stk;
vector<int> dp;

void toposort(int v){
    visited[v] = 1;

    for(auto child : adj[v]){
        if(!visited[child])
            toposort(child);
    }

    stk.push_back(v);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        int n,m;
        cin >> n >> m;
        adj = vector<vector<int>> (n+1);
        inc = vector<vector<int>> (n+1);
        visited = vector<short> (n+1,0);
        dp = vector<int> (n+1,0);

        for(int i=0 ; i<m ; i++){
            int x,y;
            cin >> x >> y;
            adj[x].push_back(y);
            inc[y].push_back(x);
        }

        for(int i=1 ; i<=n ; i++){
            if(!visited[i])
                toposort(i);
        }
        
        reverse(stk.begin(),stk.end());
        long long int output = 0;
        for(auto i : stk){
            int temp = 0;
            if(inc[i].size()==0){
                dp[i] = temp;
                continue;
            }
            for(auto parent : inc[i]){
                if(dp[parent] > temp)
                    temp = dp[parent];
            }
            dp[i] = temp+1;
            if(dp[i] > output) output = dp[i];
        }
        /*for(int i=1 ; i<=n ; i++) cout << dp[i] << " ";*/
        /*cout << "\n";*/
        cout << output << "\n";
    }
    return 0;
}

