#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    int count = 1;
    while(t--){
        int n;
        cin >> n;
        string in, out;
        cin >> in >> out;
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0 ; i<n ; i++) dp[i][i] = 1;
        for(int i=0 ; i<n-1 ; i++){
            if(out[i]=='Y' && in[i+1]=='Y')
                dp[i][i+1] = 1;
            if(out[i+1]=='Y' && in[i]=='Y')
                dp[i+1][i] = 1;
        }
        for(int i=0 ; i<n ; i++){
            for(int j=i+2 ; j<n ; j++){
                if(dp[i][j-1] & dp[j-1][j])
                    dp[i][j] = 1;
                else break;
            }
        }
        for(int i=0 ; i<n ; i++){
            for(int j=i-2 ; j>=0 ; j--){
                if(dp[i][j+1] & dp[j+1][j])
                    dp[i][j] = 1;
                else break;
            }
        }
        cout << "Case #" << count++ << ":\n";
        for(auto v : dp){
            for(auto e : v){
                if(e) cout << "Y";
                else cout << "N";
            }
            cout << "\n";
        }
    }
    return 0;
}

