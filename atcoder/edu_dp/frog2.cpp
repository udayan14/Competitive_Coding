#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<long long int> h(n);
        for(int i=0 ; i<n ; i++)
            cin >> h[i];

        vector<long long int> dp(n);
        dp[0] = 0;
        for(int i=1 ; i<n ; i++){
            long long int ans = INT_MAX;
            for(int j=1 ; j<=k && i-j >=0; j++){
                long long int temp = h[i] - h[i-j];
                if(temp<0) temp*=-1;
                if(dp[i-j] + temp < ans)
                    ans = dp[i-j] + temp;
            }
            dp[i] = ans;
        }
        cout << dp[n-1] << "\n";
    }
    return 0;
}

