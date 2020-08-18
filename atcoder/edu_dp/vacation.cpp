#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        int n;
        cin >> n;
        vector<vector<long long int>> in(n,vector<long long int>(3));
        for(int i=0 ; i<n ; i++){
            cin >> in[i][0] >> in[i][1] >> in[i][2];
        }
        
        vector<vector<long long int>> dp(n,vector<long long int>(3));
        dp[0] = in[0];
        for(int i=1 ; i<n ; i++){
            dp[i][0] = in[i][0] + max(dp[i-1][1],dp[i-1][2]);
            dp[i][1] = in[i][1] + max(dp[i-1][0],dp[i-1][2]);
            dp[i][2] = in[i][2] + max(dp[i-1][1],dp[i-1][0]);
        }
        cout << max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2])) << "\n";
    }
    return 0;
}

