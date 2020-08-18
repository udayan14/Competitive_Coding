#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include<climits>
using namespace std;


long long int n,k;
vector<long long int> f;
vector<long long int> dp;

long long int solve(int idx){
    if(dp[idx]!=-1) return dp[idx];
    if(idx==n-1){
        dp[idx] = k;
        return dp[idx];
    }
    vector<long long int> count(101,0);
    count[f[idx]]++;
    long long int min_out = LLONG_MAX;
    long long int curr_cost = 0;
    for(int i=idx+1 ; i<n ; i++){
        long long int temp = curr_cost + k + solve(i);
        if(temp < min_out)
            min_out = temp;
        if(count[f[i]]==1) curr_cost+=2;
        else if(count[f[i]]>1) curr_cost+=1;
        count[f[i]]++;
    }
    
    if(curr_cost + k < min_out)
        min_out = curr_cost + k;
    dp[idx] = min_out;
    return dp[idx];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        f = vector<long long int> (n);
        dp = vector<long long int> (n,-1);
        for(int i=0 ; i<n ; i++) cin >> f[i];

        cout << solve(0) << "\n";
    }
    return 0;
}

