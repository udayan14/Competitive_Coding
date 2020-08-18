#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include<set> 

using namespace std;

vector<set<int>> adj;
vector<set<int>> leaves;

struct cmp{
    bool operator()(int a, int b) const{
        if(leaves[a].size()==leaves[b].size()) return a > b;
        else return leaves[a].size() > leaves[b].size();
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        adj = vector<set<int>>(n+1);
        leaves = vector<set<int>>(n+1);
        int x,y;
        for(int i=0 ; i<n-1 ; i++){
            cin >> x >> y;
            adj[x].insert(y);
            adj[y].insert(x);
        }
        for(int i=1 ; i<=n ; i++){
            if(adj[i].size()==1){
                leaves[*adj[i].begin()].insert(i);
            }
        }
        set<int,cmp> s;
        for(int i=1 ; i<=n ; i++){
            s.insert(i);
        }

        int ans = 0;
        while(true){
            int curr = *s.begin();
            if(leaves[curr].size() < k) break;
            for(int i=0 ; i<k ; i++){
                int leaf = *leaves[curr].begin();
                s.erase(leaf);
                s.erase(curr);
                adj[leaf].erase(curr);
                adj[curr].erase(leaf);
                leaves[curr].erase(leaf);
                if(leaves[leaf].count(curr)) leaves[leaf].erase(curr);
                if(adj[curr].size()==1){
                    int temp = *adj[curr].begin();
                    s.erase(temp);
                    leaves[temp].insert(curr);
                    s.insert(temp);
                }
                s.insert(curr);
                s.insert(leaf);
            }

            ans++;
        }

        cout << ans << "\n";
    }
    return 0;
}

