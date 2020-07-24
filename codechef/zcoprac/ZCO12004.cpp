#include<iostream>

using namespace std;

long long int solve(int a[], int start, int end){
    //cout << "solve called with params " << start << " " << end << "\n";
    if(start+1==end)
        return 0;
    long long int dp[end];
    dp[start] = a[start];
    dp[start+1] = a[start+1];
    for(int i=start+2 ; i<end ; i++)
        dp[i] = a[i] + min(dp[i-1],dp[i-2]);
    long long int out = dp[end-1];
    //for(int i=start; i<end ; i++)
        //cout << a[i] << " ";
    //cout << "\n";
    //for(int i=start ; i<end ; i++)
        //cout << dp[i] << " ";
    //cout << "\n";
    return min(out,dp[end-2]);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0 ; i<n ; i++)
        cin >> a[i];
    if(n==1){
        cout << a[0] << "\n";
        return 0;
    }
    else if(n==2){
        cout << min(a[0],a[1]) << "\n";
        return 0;
    }
    else if(n==3){
        cout << min(a[0],min(a[1],a[2])) << "\n";
    }
    else{
        cout << min(a[0] + solve(a,1,n), a[1]+a[n-1]+solve(a,2,n-1)) << "\n";
    }
}
