//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

const long long int p = 1000000007;

vector<vector<int>> adj;
vector<int> Tin;
vector<int> Tout;
vector<int> h;
int counter = 0;


void dfs(int node, int parent, int height){
    Tin[node] = counter++;
    h[node] = height;
    for(auto child : adj[node]){
        if(child!=parent){
            dfs(child,node,height+1);
        }
    }
    Tout[node] = counter++;
}

struct Comparator{
    bool operator() (const pair<int,int> &lhs, const pair<int,int> &rhs) const{
        if(lhs.first == rhs.first){
            if(h[lhs.second]==h[rhs.second]){
                return lhs.second < rhs.second;
            }
            else return h[lhs.second] < h[rhs.second];
        }
        else return lhs.first < rhs.first;
    }
};

typedef
tree<
    pair<int,int>,
    null_type,
    Comparator,
    rb_tree_tag,
    tree_order_statistics_node_update>
set_t;


bool is_ancestor(int x, int y){
    return  Tin[x] <= Tin[y] && Tout[x] >= Tout[y];
}

long long int mod_exp(long long int x, long long int y){
    if(x==1) return 1;
    long long int res = 1;
    while(y){
        if(y&1) res = (res * x) % p;
        x = (x*x) % p;
        y >>= 1;
    }
    return res;
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
        Tin = vector<int> (n+1);
        Tout = vector<int> (n+1);
        h = vector<int> (n+1);
        counter = 0;

        int u,v;
        for(int i=0 ; i<n-1 ; i++){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1,1,0);
        set_t s;
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=n ; j++){
                if(is_ancestor(i,j)) continue;
                s.insert({i,j});
            }
        }
        //cout << s.size() << "\n";
        int q;
        cin >> q;
        
        long long int c,e;
        long long int d = 0;
        for(int i=1 ; i<=q ; i++){
            cin >> e;
            c = e ^ d;
            auto p_del = *s.find_by_order(c-1);
            s.erase(p_del);
            long long int u = p_del.first;
            long long int v = p_del.second;
            d = (d + ((u * mod_exp(2,i))%p) + ((v * mod_exp(3,i))%p)) % p;
            //cout << "Deleting " << c << " : "<< u << " " << v << " " << d << "\n";
        }
        cout << d << "\n";
    }
    return 0;
}

