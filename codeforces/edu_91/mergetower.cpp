#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

const int N = 400043;
const int LN = 21;

int dp[N][LN];
int Tin[N];
int Tout[N];
int parent[N];
vector<int> adj[N];
int counter = 0;

int dfs(int node, int p){
    parent[node] = p;
    dp[node][0] = p;
    for(int i=1 ; i<LN ; i++){
        dp[node][i] = dp[dp[node][i-1]][i-1];
    }
    Tin[node] = counter++;
    for(auto v : adj[node]){
        dfs(v,node);
    }
    Tout[node] = counter++;
}

bool is_ancestor(int x, int y){
    return Tin[x] <= Tin[y] && Tout[x] >= Tout[y];
}

int lca(int x, int y){
    if(is_ancestor(x,y))
        return x;
    for(int i=LN-1 ; i>=0 ; i--){
        if(!is_ancestor(dp[x][i],y))
            x = dp[x][i];
    }
    return parent[x];
}

int main(){
    int n,m;
    cin >> n >> m;
    int ind[n];
    int pairs[m];           // number of pairs i and i+1 in the same stack at state t stored in pairs[t];
    memset(pairs,0,sizeof(pairs));
    for(int i=0 ; i<n ; i++){
        cin >> ind[i];
        ind[i]--;
    }

    int identity[m];
    for(int i=0 ; i<m ; i++) identity[i] = i;

    for(int i=0 ; i<m-1 ; i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[m+i].push_back(identity[a]);
        adj[m+i].push_back(identity[b]);
        identity[a] = m+i;
    }
    int root = 2*m-2;
    dfs(root,root);
    for(int i=0 ; i<n-1 ; i++){
        if(ind[i]==ind[i+1])
            pairs[0]++;
        else{
            int lca_node = lca(ind[i],ind[i+1]);
            pairs[lca_node-m+1]++;
        }
    }
    //for(int i=0 ; i<m ; i++) cout << pairs[i] << " ";
    //cout << "\n";
    for(int i=0 ; i<m-1 ; i++)
        pairs[i+1] += pairs[i];
    for(int i=0 ; i<m ; i++){
        cout << n-1-pairs[i] << "\n";
    }
}
