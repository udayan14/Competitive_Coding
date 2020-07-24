#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0 ; i<n ; i++)
        cin >> a[i];
    vector<int> pal[n];
    for(int i=0 ; i<n ; i++){
        for(int j=i ; j<n ; j++){
            int start = i;
            int end = j;
            bool flag = true;
            while(start<end){
                if(a[start]==a[end]){
                    start++;
                    end--;
                }
                else{
                    flag = false;
                    break;
                }
            }
            if(flag)
                pal[i].push_back(j);
        }
    }
    int dp[n+1];
    dp[n] = 0;
    dp[n-1] = 1;
    for(int i=n-2 ; i>=0 ; i--){
        dp[i] = 1000;
        for(const auto ind : pal[i]){
            dp[i] = min(dp[i],1+dp[ind+1]);
        }
    }
    cout << dp[0] << "\n";
}
