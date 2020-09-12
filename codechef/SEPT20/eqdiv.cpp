//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> k;
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        vector<short> group(n+1,0);
        if(k==1){
            long long int sum1 = 0;
            long long int sum2 = 0;
            for(int i=n ; i>0 ; i--){
                if(sum1 > sum2){
                    sum2 += i;
                    group[i] = 1;
                }
                else{
                    sum1 += i;
                }
            }
            long long int ans = sum1 - sum2;
            if(ans < 0) ans *= -1;
            cout << ans << "\n";
            for(int i=1 ; i<=n ; i++) cout << group[i];
            cout << "\n";
        }
        else if(k==2){
            long long int sum1 = 0;
            long long int sum2 = 0;
            for(int i=n ; i>0 ; i--){
                if(sum1 > sum2){
                    sum2 += i*i;
                    group[i] = 1;
                }
                else{
                    sum1 += i*i;
                }
            }
            long long int ans = sum1 - sum2;
            if(ans < 0) ans *= -1;
            cout << ans << "\n";
            for(int i=1 ; i<=n ; i++) cout << group[i];
            cout << "\n";

        }
    }
    return 0;
}

