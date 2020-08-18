#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>

#define p 1000000007

using namespace std;

vector<int> a;
vector<long long int> sum_a;
vector<vector<long long int>> dp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        int n,k;
        cin >> n >> k;
        a = vector<int> (n);
        sum_a = vector<long long int> (n+1);
        sum_a[0] = 0;
        dp = vector<vector<long long int>> (n,vector<long long int> (k+1,0));
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
            sum_a[i+1] = sum_a[i] + a[i];
        }
        for(int i=0 ; i<n ; i++){
            for(int sum=0 ; sum<=sum_a[i+1] && sum<=k; sum++){
                if(i==0 || sum==0){
                    dp[i][sum] = 1;
                    continue;
                }
                dp[i][sum] = (dp[i][sum-1] + dp[i-1][sum])%p;
                if(sum-a[i]-1 >=0){
                    dp[i][sum] = (dp[i][sum] - dp[i-1][sum-a[i]-1])%p;
                    if(dp[i][sum] < 0) dp[i][sum] += p;
                }
            }
        }
        cout << dp[n-1][k] << "\n";
    }
    return 0;
}

