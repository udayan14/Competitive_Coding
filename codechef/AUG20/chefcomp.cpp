//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p;
vector<int> a;
vector<int> b;
vector<int> visited;
vector<int> d;
vector<vector<int>> adj;

int day;
int val;

void dfs(int v, int p){
    if(b[v] > 0){
        b[v] -= val;
        if(b[v] <= 0){
            b[v] = 0;
            d[v] = day;
        }
    }
    for(auto child : adj[v]){
        if(child!=p && visited[child]==0){
            dfs(child,v);
        }
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
        p = vector<int> (n+1);
        a = vector<int> (n+1);
        b = vector<int> (n+1);
        
        int x,y;
        for(int i=0 ; i<n-1 ; i++){
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i=1 ; i<=n ; i++) cin >> p[i];
        for(int i=1 ; i<=n ; i++) cin >> a[i];
        for(int i=1 ; i<=n ; i++) cin >> b[i];

        visited = vector<int> (n+1,0);

        d = vector<int> (n+1,-1);

        day = 1;
        for(int i=1 ; i<=n ; i++){
            val = a[p[i]];
            dfs(p[i],p[i]);
            visited[p[i]] = 1;
            day++;
        }

        for(int i=1 ; i<=n ; i++){
            cout << d[i]  << " ";
        }
        cout << "\n";
    }
    return 0;
}

