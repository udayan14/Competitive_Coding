#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

#define N 200001
#define A_max 101
#define LN 21

vector<int> adj[N+1];
int parent[N+1];
int depth[N+1];
int dp[LN][N+1];

void dfs(int node, int par, int d){
    depth[node] = d;
    parent[node] = par;
    for(int i=1 ; i<LN ; i++)
        dp[i][node] = dp[i-1][dp[i-1][node]];
    for(const auto &v : adj[node]){
        if(v!=par){
            dp[0][v] = node;
            dfs(v,node,d+1);
        }
    }
}

void print_arr(int a[], int n){
    for(int i=0 ; i<n ; i++)
        cout << a[i] << " ";
    cout << "\n";
}

int lca(int u, int v){
    if(depth[u] > depth[v])
        swap(u,v);
    for(int i=LN-1 ; i>=0 ; i--){
        if(depth[v] - (1<<i) >= depth[u])
            v = dp[i][v];
    }
    //depths are equal at this stage
    if(u==v) return u;
    for(int i=LN-1 ; i>=0 ; i--){
        if(dp[i][u]!=dp[i][v]){
            u = dp[i][u];
            v = dp[i][v];
        }
    }
    //u and v have the same parent viz lca
    return dp[0][u];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        int A[n+1];
        for(int i=1 ; i<=n ; i++)
            cin >> A[i];
        for(int i=1 ; i<=n ; i++)
            adj[i].clear();

        for(int i=1 ; i<n ; i++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dp[0][1] = 1;
        dfs(1,-1,0);
        while(q--){
            int a,b;
            cin >> a >> b;
            int temp = lca(a,b);
            //cout << "LCA is " << temp << "\n";
            int num_nodes = (depth[a] - depth[temp] + 1) + (depth[b] - depth[temp] + 1) - 1;
            if(num_nodes>100){
                cout << "0\n";
                continue;
            }
            int tmp[num_nodes];
            int index = 0;
            while(a!=temp){
                //cout << "Adding value " << A[a] << " for node " << a << "\n";
                tmp[index++]=A[a];
                a = parent[a];
            }
            while(b!=temp){
                //cout << "Adding value " << A[b] << " for node " << b << "\n";
                tmp[index++]  = A[b];
                b = parent[b];
            }
            tmp[index++] = A[temp];
            //print_arr(tmp,num_nodes);
            sort(tmp,tmp+num_nodes);
            //print_arr(tmp,num_nodes);
            int curr_min = tmp[1] - tmp[0];
            for(int i=1 ; i<num_nodes ; i++){
                int diff = tmp[i] - tmp[i-1];
                if(diff < curr_min)
                    curr_min = diff;
            }
            cout << curr_min << "\n";
        }
    }
}
