#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;

# define VMAX 100000
#define NMAX 100
#define inf 1e18+3
vector<long long int> w;
vector<long long int> v;
vector<vector<long long int>> dp;
// dp[i][j] is the minimum weight required to carry items with index <= i with value totaling exactly j

long long int find(int i, int val){
    if(dp[i][val]!=-1) return dp[i][val];
    if(val==0){
        dp[i][val] = 0;
        return dp[i][val];
    }
    if(i==0){
        if(v[i]==val){
            dp[i][val] = w[i];
            return dp[i][val];
        }
        else{
            dp[i][val] = inf;
            return dp[i][val];
        }
        
    }
    dp[i][val] = find(i-1,val);
    
    if(v[i]>val){
        return dp[i][val];
    }
    else{
        dp[i][val] = min(find(i-1,val),w[i] + find(i-1,val-v[i]));
        return dp[i][val];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        long long int n,k;
        cin >> n >> k;
        w = vector<long long int> (n);
        v = vector<long long int> (n);
        int total_value = 0;
        for(int i=0 ; i<n ; i++){
            cin >> w[i] >> v[i];
            total_value += v[i];
        }
        dp = vector<vector<long long int>> (n,vector<long long int>(total_value+1,-1));
        int output = 0;
        for(int i=0 ; i<=total_value ; i++){ 
            if(find(n-1,i) <= k)
                output = i;
        }
        cout << output << "\n";
    }   
    return 0;
}

