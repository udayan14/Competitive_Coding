#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;

vector<long long int> a;
vector<vector<long long int>> dp;

long long int find(int i, int j){
    if(dp[i][j]!=-1) return dp[i][j];

    if(i==j)
        dp[i][j] = a[i];
    else
        dp[i][j] = max(a[i] - find(i+1,j), a[j] - find(i,j-1));
    return dp[i][j];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        int n;
        cin >> n;
        a = vector<long long int> (n);
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        
        dp = vector<vector<long long int>> (n,vector<long long int>(n,-1));

        cout << find(0,n-1) << "\n";
    }
    return 0;
}

