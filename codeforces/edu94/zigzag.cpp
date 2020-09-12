//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));  //dp[i][j] is the count of i occuring in the array a between indices 0,..,i-1
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        for(int i=0 ; i<n ; i++){
            for(int val = 1 ; val<=n ; val++){
                dp[val][i+1] = dp[val][i];
            }
            dp[a[i]][i+1]++;
        }
        long long int output = 0;
        
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                output += dp[a[j]][i] * (dp[a[i]][n] - dp[a[i]][j+1]);
            }
        }
        

        cout << output << "\n";

    }
    return 0;
}

