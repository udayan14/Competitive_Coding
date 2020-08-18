#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<long long int> p;
vector<long long int> h;
bool flag;

int dfs(int v, int par){
    long long int temp = 0;
    long long int total = p[v];
    int child_visits = 0;
    for(auto child : adj[v]){
        if(child!=par){
            int child_flow = dfs(child,v);
            total += child_flow;
            temp += h[child];
            child_visits++;
        }
    }
    if((total-h[v])%2!=0) flag = false; 
    if(h[v] < temp - p[v] && child_visits>0){
        //cout << "Fails here with " << h[v] << " " << temp << " " << total <<"\n";
        flag = false;
    }
    if((h[v]<0 && total < -h[v])||(h[v]>0 && total < h[v])){
        //cout << "case 2 Fails here with " << h[v] << " " << temp << " " << total <<"\n";
        flag = false;
    }
    return total;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        adj = vector<vector<int>>(n+1);
        p = vector<long long int> (n+1);
        h = vector<long long int> (n+1);
        for(int i=0 ; i<n ; i++){
            cin >> p[i+1];
        }
        for(int i=0 ; i<n ; i++){
            cin >> h[i+1];
        }
        int x,y;
        for(int i=0 ; i<n-1 ; i++){
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        flag = true;
        
        
        dfs(1,1);
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

