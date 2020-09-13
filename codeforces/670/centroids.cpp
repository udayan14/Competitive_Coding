//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<int> centroids;
vector<int> sz;
int n;

void dfs(int node, int par){
    sz[node] = 1;
    bool is_centroid = true;
    for(auto child : adj[node]){
        if(child!= par){
            dfs(child,node);
            sz[node] += sz[child];
            if(sz[child] > n/2){
                is_centroid = false;
            }
        }
    }
    if(n - sz[node] > n/2){
        is_centroid = false;
    }
    if(is_centroid) centroids.push_back(node);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n;

        adj = vector<vector<int>> (n+1);
        sz = vector<int> (n+1);
        centroids.clear();
        int x,y;
        for(int i=0 ; i<n-1 ; i++){
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1,1);
        if(centroids.size()==1){
            for(int i=1 ; i<=n ; i++){
                if(adj[i].size() > 0){
                    cout << i << " " << adj[i][0] << "\n";
                    cout << i << " " << adj[i][0] << "\n";
                    break;
                }
            }
        }
        else{
            int u = centroids[0];
            int v = centroids[1];
            for(auto node: adj[u]){
                if(node != v){
                    cout << u << " " << node << "\n";
                    cout << node << " " << v << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}

