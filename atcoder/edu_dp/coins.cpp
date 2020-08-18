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
        vector<double> p(n);
        for(int i=0 ; i<n ; i++) cin >> p[i];

        vector<vector<double>> dp(n,vector<double>(n+1,0.0));
        //dp[i][j] corresponds to probability of getting j heads in first i+1 coins
        dp[0][0] = 1 - p[0];
        dp[0][1] = p[0];
        for(int i=1 ; i<n ; i++){
            for(int j=0 ; j<n+1 ; j++){
                if(j==0){
                    dp[i][j] = dp[i-1][j] * (1.0 - p[i]);
                }
                else
                    dp[i][j] = dp[i-1][j] * (1.0 - p[i]) + dp[i-1][j-1] * p[i];
            }
        }
        double out = 0.0;
        for(int i=n/2+1 ; i<=n ; i++)
            out += dp[n-1][i];
        cout.precision(10);
        cout << out << "\n";
    }
    return 0;
}

