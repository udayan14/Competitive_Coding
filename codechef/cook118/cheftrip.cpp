#include<bits/stdc++.h>

using namespace std;

class subset{
    public:
    int parent;
    int rank;
};

int find(subset subsets[], int i){
     //find root and make root as parent of i
    // (path compression)
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}
// A function that does union of two sets of x and y
// (uses union by rank)
void Union(subset subsets[], int x, int y){
     int xroot = find(subsets, x);
     int yroot = find(subsets, y);
   if(subsets[xroot].rank < subsets[yroot].rank)
       subsets[xroot].parent = yroot;
   else if (subsets[xroot].rank > subsets[yroot].rank)
       subsets[yroot].parent = xroot;
// If ranks are same, then make one as root and
// increment its rank by one
    else{
         subsets[yroot].parent = xroot;
         subsets[xroot].rank++;
     }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        vector<int> adj[n];
        for(int i=1 ; i<n ; i++){
            int x,y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<pair<int,int>> a(n+1);
        int val[n+1];
        for(int i=1 ; i<=n ; i++){
            int in;
            cin >> in;
            a[i] = make_pair(in,i);
            val[i] = in;
        }
        int visited[n+1];
        memset(visited,0,sizeof(visited));
        make_heap(a.begin(),a.end());
        stack<pair<int,int> > s;
        pair<int,int> curr;
        while(!a.empty()){
            do{
                curr = a.front();
                pop_heap(a.begin(),a.end());
                a.pop_back();
            }while(visited[curr] && !a.empty())

            if(visited[curr]) break;
            s.push(curr);
            while(!s.empty()){
                pair<int,int> top = s.top();
                int ind = top.first;
                int Aval = top.second;
                visited[ind] = 1;
            }

        }
    }
}
