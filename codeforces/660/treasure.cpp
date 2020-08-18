#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;



vector<vector<int>> adj;
vector<int> visited;
vector<int> stk1;
vector<int> stk2;
vector<long long int> a;
vector<int> b;
void toposort(int v){
    visited[v] = 1;
    for(auto child : adj[v]){
        if(!visited[child])
            toposort(child);
    }
    stk1.push_back(v);
    return;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        int n;
        cin >> n;
        long long int output = 0;
        adj = vector<vector<int>> (n+1);
        a = vector<long long int> (n+1);
        b = vector<int> (n+1);
        visited = vector<int>(n+1,0);
        for(int i=0 ; i< n ; i++){
            cin >> a[i+1];
            //cout << "i";
        }
        for(int i=1 ; i<=n ; i++){
            cin >> b[i];
            if(b[i]!=-1)
                adj[i].push_back(b[i]);
        }
        
        for(int i=1 ; i<=n ; i++){
            if(!visited[i])
                toposort(i);
        }
        reverse(stk1.begin(),stk1.end());
        vector<int> out;
        for(auto e : stk1){
            if(a[e]>=0){
                out.push_back(e);
                output+=a[e];
                if(b[e]!=-1){
                    a[b[e]]+=a[e];
                }
            }
            else{
                stk2.push_back(e);
            }
        }
        reverse(stk2.begin(),stk2.end());
        for(auto e : stk2){
            out.push_back(e);
            output+=a[e];
            if(b[e]!=-1)
                a[b[e]] += a[e];
        }
        cout << output << "\n";
        for (auto e : out)
            cout << e << " ";
        cout << "\n";
        stk1.clear();
        stk2.clear();
        out.clear();
    }
    return 0;
}

