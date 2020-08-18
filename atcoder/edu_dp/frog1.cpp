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
        vector<long long int> h(n);
        for(int i=0 ; i<n ; i++)
            cin >> h[i];
        vector<long long int> dp(n);
        dp[0] = 0;
        dp[1] = h[0] - h[1];
        if(dp[1]<0) dp[1] *= -1;

        for(int i=2 ; i<n ; i++){
            long long int temp1 = h[i] - h[i-1];
            if(temp1 < 0) temp1 *= -1;
            long long int temp2 = h[i] - h[i-2];
            if(temp2 < 0) temp2 *= -1;

            dp[i] = min(dp[i-1] + temp1, dp[i-2] + temp2);

        }
        cout << dp[n-1] << "\n";
    }
    return 0;
}

