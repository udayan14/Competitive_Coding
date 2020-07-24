#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

long long int out1 = 1;
long long int out2 = 1;
const int NMAX = 100;
vector<int> adj[NMAX+1];
vector<long long int> out(NMAX+1);
int counter1 = 4;
int counter2 = 4;

vector<long long int> primes1 = {3,7,13,19,29,37,43,53,61,71,79,89};
vector<long long int> primes2 = {2,5,11,17,23,31,41,47,59,67,73,83,97};

void dfs(int node, int parent, int parity){
    if(parity==0) out[node] = out2/(primes2[counter2++]);
    else out[node] = out1/(primes1[counter1++]);
    if(counter1==12) counter1 = 4;
    if(counter2==12) counter2 = 4;
    parity = 1 - parity;

    for(auto v : adj[node]){
        if(v!=parent){
            dfs(v,node,parity);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i=0 ; i<primes1.size() ; i++){
        out1*=primes1[i];
    }
    for(int i=0 ; i<primes2.size() ; i++){
        out2*=primes2[i];
    }
    
    //cout << out1 << " " << out2 << "\n";
    while(t--){
        int n;
        cin >> n;
        for(int i=1 ; i<=n ; i++) adj[i].clear();

        for(int i=0 ; i<n-1 ; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1,1,0);
        for(int i=1 ; i<=n ; i++){
            assert(out[i]<2000000000000000000);
            cout << out[i] << " ";
        }
        cout << "\n";
    }
}
