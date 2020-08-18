#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long int> r;
vector<long long int> g;
vector<long long int> b;
vector<vector<vector<long long int>>> dp;

long long int find(int i, int j, int k){
    //cout << "called with " << i << j << k << "\n";
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    long long int output = 0;
    if(i>0)
        output = max(output,find(i-1,j,k));
    if(j>0)
        output = max(output,find(i,j-1,k));
    if(k>0)
        output = max(output,find(i,j,k-1));
    if((i>0) && (j>0))
        output = max(output,r[i-1]*g[j-1] + find(i-1,j-1,k));
    if((i>0) && (k>0))
        output = max(output,r[i-1]*b[k-1] + find(i-1,j,k-1));
    if((j>0) && (k>0))
        output = max(output,g[j-1]*b[k-1] + find(i,j-1,k-1));
    dp[i][j][k] = output;
    return dp[i][j][k];


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        int rc, gc, bc;
        cin >> rc >> gc >> bc;
        r = vector<long long int> (rc);
        g = vector<long long int> (gc);
        b = vector<long long int> (bc);
        dp = vector<vector<vector<long long int>>> (rc+1, vector<vector<long long int>>(gc+1,vector<long long int>(bc+1,-1)));

        for(int i=0 ; i<rc ; i++) cin >> r[i];
        for(int i=0 ; i<gc ; i++) cin >> g[i];
        for(int i=0 ; i<bc ; i++) cin >> b[i];
        
        sort(r.begin(),r.end());
        sort(g.begin(),g.end());
        sort(b.begin(),b.end());
        cout << find(rc,gc,bc) << "\n";
    }
    return 0;
}

