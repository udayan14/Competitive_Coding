#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    long long int dp[n];
    long long int sum = 0;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
        sum+=a[i];
    }
    dp[0] = a[0];
    dp[1] = a[1];
    dp[2] = a[2];
    for(int i=3 ; i<n ; ++i){
        dp[i] = a[i] + min(dp[i-1],min(dp[i-2],dp[i-3]));
    }
    long long int out = dp[n-1];
    for(int i=1 ; i<3 && n-1-i>0; i++)
        out = min(out,dp[n-i-1]);
    cout << sum - out << "\n";
}
