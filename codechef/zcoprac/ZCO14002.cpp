#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n+1];
    int dp[n+1];
    for(int i=1 ; i<=n ; ++i)
        cin >> a[i];
    dp[1] = a[1];
    dp[2] = a[2];
    dp[3] = a[3];
    for(int i=4 ; i<=n ; ++i)
        dp[i] = min(a[i] + dp[i-1], min(a[i] + dp[i-2], dp[i-3] + a[i]));
    int output = dp[n];
    for(int i=1 ; (i<3) && (n-i>=0) ; i++)
        output = min(output,dp[n-i]);
    cout <<  output << "\n";
}
