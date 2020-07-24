#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<stack>

using namespace std;

const int NMAX = 200000;

vector<int> adj[NMAX+1];
short visited[NMAX+1];
short rec[NMAX+1];
vector<int> s;
int index_arr[NMAX+1];

void dfs(int v){
    visited[v] = true;
    for(auto child: adj[v]){
        if(!visited[child]){
            dfs(child);
        }
    }
    s.push_back(v);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        for(int i=1 ; i<=n ; i++)
            adj[i].clear();
        memset(visited,0,(n+1)*sizeof(visited[0]));
        memset(rec,0,(n+1)*sizeof(rec[0]));
        vector<pair<int,int> > uedges;
        for(int i=0 ; i<m ; i++){
            int t,x,y;
            cin >> t >> x >> y;
            if(t){
                adj[x].push_back(y);
            }
            else{
                uedges.push_back({x,y});
            }
        }
        bool flag = true;
        for(int i=1 ; i<=n ; i++){
            if(visited[i]==0){
                dfs(i);
            }
        }
        reverse(s.begin(),s.end());

        int counter = 0;
        for(auto ele : s){
            index_arr[ele] = counter++;
        }
        s.clear();
        for(int i=1 ; i<=n && flag ; i++){
            for(auto node : adj[i]){
                if(index_arr[node]<index_arr[i]){
                    flag = false;
                    break;
                }
            }
        }
        if(!flag){
            cout << "NO\n";
            continue;
        }

        //for(int i=1 ; i<=n ; i++) cout << i << " : " << index_arr[i] << " || ";
        //cout << "\n";
        cout << "YES\n";
        for(int i=1 ; i<=n ; i++){
            for(auto v : adj[i]){
                cout << i << " " << v << "\n";
            }
        }
        for(auto vvpair : uedges){
            int x = vvpair.first;
            int y = vvpair.second;
            if(index_arr[x] > index_arr[y])
                cout << y << " " << x << "\n";
            else
                cout << x << " " << y << "\n";
        }
    }
}
