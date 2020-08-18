#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;

#define p 1000000007

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        int h,w;
        cin >> h >> w;
        vector<vector<char>> a(h,vector<char>(w));
        for(int i=0 ; i<h ; i++){
            for(int j=0 ; j<w ; j++){
                cin >> a[i][j];
            }
        }
        vector<vector<int>> dp(h,vector<int>(w,0));
        dp[0][0] = 1;
        for(int i=1 ; i<h ; i++){
            if(a[i][0]=='.')
                dp[i][0] = dp[i-1][0];
            else break;
        }
        for(int j=1 ; j<w ; j++){
            if(a[0][j]=='.')
                dp[0][j] = dp[0][j-1];
            else break;
        }

        for(int i=1 ; i<h ; i++){
            for(int j=1 ; j<w ; j++){
                if(a[i][j]=='.')
                    dp[i][j] = (dp[i-1][j] + dp[i][j-1])%p;
            }
        }
        cout << dp[h-1][w-1] << "\n";
    }
    return 0;
}

