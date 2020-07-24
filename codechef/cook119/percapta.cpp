#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;

        vector<int> adj[n+1];
        for(int i=1 ; i<=n ; i++)
            adj[i].clear();

        long long int income[n+1];
        long long int pop[n+1];
        for(int i=1 ; i<=n ; i++)
            cin >> income[i];
        for(int i=1 ; i<=n ; i++)
            cin >> pop[i];
        
        long long int curr_income = income[1];
        long long int curr_pop = pop[1];
        for(int i=2 ; i<=n ; i++){
            if(income[i]*curr_pop > curr_income*pop[i]){
                curr_pop = pop[i];
                curr_income = income[i];
            }
        }

        int u,v;
        while(m--){
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int feasible[n+1];
        memset(feasible,0,sizeof(feasible));
        for(int i=1 ; i<=n ; i++){
            if(income[i]*curr_pop == curr_income*pop[i])
                feasible[i] = 1;
        }

        int out1 = -1;
        vector<int> out2;
        out2.clear();
        int visited[n+1];
        memset(visited,0,sizeof(visited));

        for(int i=1 ; i<=n ; i++){
            if(!feasible[i]){
                visited[i] = 1;
                continue;
            }
            if(visited[i])
                continue;

            int temp1 = 0;
            vector<int> temp2;
            temp2.clear();
            //do BFS
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            while(!q.empty()){
                int curr = q.front();
                q.pop();
                temp1++;
                temp2.push_back(curr);
                for(const auto &v : adj[curr]){
                    if(feasible[v] && !visited[v]){
                        q.push(v);
                        visited[v] = 1;
                    }
                }
            }
            if(temp1>out1){
                out1 = temp1;
                out2 = temp2;
            }
        }
        cout << out1 << "\n";
        for(const auto &v : out2)
            cout << v << " ";
        cout << "\n";
    }
}
