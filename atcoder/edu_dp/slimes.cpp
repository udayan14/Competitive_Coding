#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <climits>
using namespace std;

vector<long long int> a;
vector<vector<long long int>> dp;
vector<long long int> sum_a;

long long int find(long long int i, long long int j){
    if(dp[i][j]!=-1) return dp[i][j];

    if(i==j){
        dp[i][j] = 0;
    }
    else{
        long long int merge_cost = sum_a[j+1] - sum_a[i];
        long long int out = LLONG_MAX;
        for(int k=i ; k<j ; k++){
            long long int temp = find(i,k) + find(k+1,j) + merge_cost;
            if(temp < out) out = temp;
        }
        dp[i][j] = out;
    }

    return dp[i][j];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        long long int n;
        cin >> n;
        a = vector<long long int> (n);
        sum_a = vector<long long int> (n+1);
        dp = vector<vector<long long int>> (n,vector<long long int>(n,-1));
        sum_a[0] = 0;
        for(long long int i=0 ; i<n ; i++){
            cin >> a[i];
            sum_a[i+1] = sum_a[i] + a[i];
        }
        long long int output = find(0,n-1);
        cout << output << "\n";
    }
    return 0;
}

