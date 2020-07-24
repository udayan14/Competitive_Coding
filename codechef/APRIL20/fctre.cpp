// This solution heavily uses code available online at https://ideone.com/6NVoPD
// I have only made minor modifications to the code to run it for this contest

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cmath>

using namespace std;

int l[100001];
int r[100001];
long long int ANS[100001];
int ID[200002];
int BL[200002];
int VIS[100001];
const int LN = 21;
int DP[LN][100001];
int curr = 0;
long long int p = 1000000007;
int primes[168];

struct query{
    int id,l,r,lc;
    bool operator<(const query &q){
        int x = BL[l];
        int y = BL[q.l];
        if(x!=y)
            return x < y;
        return (x%2) ? (r < q.r) : r > q.r;
    }
};

int sieveOfEratosthenes(){
    memset(primes,0,sizeof(primes));
    int N = 1001;
    int mask[N];
    memset(mask,1,sizeof(mask));
    mask[0] = 0;
    mask[1] = 0;
    int count = 0;
    for(long long int i=2 ; i<N ; ++i){
        if(mask[i]){
            primes[count++] = i;
            for(long long int j=2 ; i*j < N ; ++j){
                mask[i*j] = 0;
            }
        }
    }
    return count;    
}


void dfs(int v, int p, int d, int depth[], int parent[], vector<int> edge[]){
    parent[v] = p;
    depth[v] = d;
    l[v] = ++curr;
    ID[curr] = v;
    for(int i=1 ; i<LN ; ++i){
        DP[i][v] = DP[i-1][DP[i-1][v]];
    }
    for(int child : edge[v]){
        if(child!=p){
            DP[0][child] = v;
            dfs(child,v,d+1,depth,parent,edge);
        }
    }
    r[v] = ++curr;
    ID[curr] = v;
}

int lca(int u,int v, int depth[]){
    if(depth[u] > depth[v])  //Ensure depth[u] <= depth[v]
        swap(u,v);
    for(int i=LN-1 ; i>=0 ; i--){
        if(depth[v] - (1<<i) >= depth[u])
            v = DP[i][v];
    }
    //Depths are equal
    if(u==v) return u;
    for(int i=LN-1 ; i>=0 ; i--){
        if(DP[i][u]!=DP[i][v]){
            u = DP[i][u];
            v = DP[i][v];
        }
    }
    // u and v have same parent at the end of this loop
    u = DP[0][u];
    return u;
}

void solve(int u,int v, int depth[], int parent[], unordered_map<int,int> A[]){
    cout << "The LCA is :" << lca(u,v,depth) << "\n"; 
}

void printArray(int a[], int n){
    for(int i=0 ; i<n ; ++i)
        cout << a[i] << " ";
    cout << "\n";
}

void check(int x, const unordered_map<int,int> A[], unordered_map<int,long long int> &temp){
    if(VIS[x]){
        for(const auto &kvpair : A[x])
            temp[kvpair.first] -= kvpair.second;
    }
    else{
        for(const auto &kvpair : A[x])
            temp[kvpair.first] += kvpair.second;
    }
    VIS[x] ^= 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int lim = sieveOfEratosthenes();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> edge[n+1];
        int parent[n+1];
        int depth[n+1];
        unordered_map<int,int> A[n+1];
        for(int i=0 ; i<n+1 ; i++){
            edge[i].clear();
            A[i].clear();
        }
        for(int i=0 ; i<n-1 ; ++i){
            int x,y;
            cin >> x >> y;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        curr = 0;
        DP[0][1] = 1;
        memset(VIS,0,sizeof(VIS));
        dfs(1,-1,0,depth,parent,edge);
        int size = 630;
        for(int i=1 ; i<=curr ; i++) 
            BL[i] = (i-1)/size + 1;
        for(int j=1 ; j<=n ; ++j){
            int in;
            cin >> in;
            for(int i=0 ; i<lim && in!=1 ; ++i){
                int count = 0;
                while(in%primes[i]==0){
                    in/=primes[i];
                    count++; 
                }
                if(count) A[j][primes[i]] = count;
            }
            if(in!=1) A[j][in] = 1;
        }
        //printArray(l,n+1);
        //printArray(r,n+1);
        //printArray(ID,2*n+1);
        int q;
        cin >> q;
        query Q_arr[q];
        for(int i=0 ; i<q ; ++i){
            int u,v;
            cin >> u >> v;
            Q_arr[i].id = i;
            Q_arr[i].lc = lca(u,v,depth);
            if(l[u] > l[v]) swap(u,v);
            if(Q_arr[i].lc==u){
                Q_arr[i].l = l[u];
                Q_arr[i].r = l[v];
            }
            else{
                Q_arr[i].l = r[u];
                Q_arr[i].r = l[v];
            }
            //cout << "The range is " << Q_arr[i].l << " " << Q_arr[i].r << " " << Q_arr[i].lc << "\n";
        }
        sort(Q_arr,Q_arr+q);
        //cout << "Queries sorted are : \n";
        //for(int i=0 ; i<q ; i++){
            //cout << Q_arr[i].id << " ";
        //}
        //cout << "\n";
        int cur_L = Q_arr[0].l;
        int cur_R = Q_arr[0].l-1;
        unordered_map<int,long long int> temp;
        temp.clear();
        for(int i=0 ; i<q ; i++){
            while(cur_L < Q_arr[i].l) check(ID[cur_L++],A,temp);
            while(cur_L > Q_arr[i].l) check(ID[--cur_L],A,temp);
            while(cur_R < Q_arr[i].r) check(ID[++cur_R],A,temp);
            while(cur_R > Q_arr[i].r) check(ID[cur_R--],A,temp);

            int u = ID[cur_L];
            int v = ID[cur_R];
            
            if(Q_arr[i].lc!=u && Q_arr[i].lc!=v)
                check(Q_arr[i].lc,A,temp);
            
            long long int output = 1;
            for(const auto &kvpair : temp)
                output = (output*(1+kvpair.second))%p;
            ANS[Q_arr[i].id] = output;
            
            if(Q_arr[i].lc!=u && Q_arr[i].lc!=v)
                check(Q_arr[i].lc,A,temp);
            
        }
        for(int i=0 ; i<q ; i++)
            cout << ANS[i] << "\n";
    }
}
