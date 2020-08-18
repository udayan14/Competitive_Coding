#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        vector<short> dp(k+1,0);
        for(int i=0 ; i<=k ; i++){
            bool found = false;
            for(int j=0 ; j<n && i-a[j]>=0 && !found ; j++){
                if(dp[i-a[j]]==0)
                    found = true;
            }
            if(found) dp[i] = 1;
        }

        if(dp[k]) cout <<  "First\n";
        else cout << "Second\n";
    }
    return 0;
}

