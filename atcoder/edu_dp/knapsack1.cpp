#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;

vector<long long int> w;
vector<long long int> v;
vector<vector<long long int>> dp;

long long int find(int n, int W){
    if(n==0 || W==0){
        dp[n][W] = 0;
        return 0;
    }
    if(dp[n][W]!=-1) return dp[n][W];
    long long int output = 0;

    if(W-w[n-1]>=0){
        output = max(find(n-1,W), v[n-1] + find(n-1,W-w[n-1]));
    }
    else{
        output = find(n-1,W);
    }
    
    dp[n][W] = output;
    return output;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        int n,W;
        cin >> n >> W;
        w = vector<long long int>(n);
        v = vector<long long int>(n);
        for(int i=0 ; i<n ; i++){
            cin >> w[i] >> v[i];
        }

        dp = vector<vector<long long int>>(n+1,vector<long long int> (W+1,-1));
        
        long long int output = find(n,W);
        cout << output << "\n";
    }
    return 0;
}

