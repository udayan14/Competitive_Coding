#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;

vector<vector<short>> a;
vector<vector<long long int>> dp;

const long long int p = 1e9 + 7;
int n;

long long int find(int i, long long int mask){
    if(dp[i][mask]!=-1) return dp[i][mask];

    if(i==0){
        long long int temp=0;
        for(int j=0 ; j<n ; j++){
            if(a[i][j])
                if(mask & (1<<j))
                    temp = 1;
        }
        dp[i][mask] = temp;
        return dp[i][mask];
    }

    long long int temp = 0;
    for(int j=0 ; j<n ; j++){
        if(a[i][j]==1){
            if(mask&(1<<j)){
                temp += find(i-1,mask^(1<<j));
                if(temp>p) temp-=p;
            }
        }
    }
    dp[i][mask] = temp;
    return dp[i][mask];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        cin >> n;
        a = vector<vector<short>> (n,vector<short>(n));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                cin >> a[i][j];
            }
        }
        dp = vector<vector<long long int>> (n,vector<long long int>((1<<n),-1));

        cout << find(n-1,(1<<n)-1) << "\n";
    }
    return 0;
}

