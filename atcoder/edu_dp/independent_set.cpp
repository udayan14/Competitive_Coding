#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;

vector<long long int> white;
vector<long long int> black;
vector<vector<int>> adj;
const long long int p = 1e9 + 7;

void dfs(int node, int parent){
    if(adj[node].size()==1 && adj[node][0]==parent){
        //leaf node
        white[node] = 1;
        black[node] = 1;
        return;
    }

    for(auto child : adj[node]){
        if(child!=parent)
            dfs(child,node);
    }

    long long int temp_b = 1;
    long long int temp_w = 1;

    for(auto child: adj[node]){
        if(child!=parent){
            temp_b = (temp_b * white[child])%p;
            temp_w = (temp_w * ((white[child] + black[child])%p))%p;
        }
    }
    white[node] = temp_w;
    black[node] = temp_b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        int n;
        cin >> n;
        white = vector<long long int> (n+1,-1);
        black = vector<long long int> (n+1,-1);
        adj = vector<vector<int>> (n+1);
        int x,y;
        for(int i=0 ; i<n-1 ; i++){
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1,1);
        cout << (white[1] + black[1])%p << "\n";
    }
    return 0;
}

