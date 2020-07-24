#include<iostream>
#include<unordered_map>

using namespace std;

long long int mod = 998244353;

long long int mod_exp(long long int x, long long int y){
    if(x==1) return 1;
    if(y==0) return 1;
    long long int temp = mod_exp(x,y/2);
    long long int out = (temp*temp)%mod;
    return ((y%2)==0)? out : (out*x)%mod;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        unordered_map<long long int,long long int> count;
        for(int i=0 ; i<n ; i++){
            long long int in;
            cin >> in;
            count[in]++;
        }
        long long int ans = 0;
        long long int lhs = 1;
        long long int rhs = n;
        for(long long int i=1 ;; i++){
            rhs -= count[i];
            ans += (i*((lhs*mod_exp(2,rhs))%mod))%mod;
            lhs = (lhs * ((mod_exp(2,count[i])-1)%mod))%mod;
            if(lhs<0) lhs+=mod;
            if(ans>mod) ans = ans%mod;
            if(count[i]==0) break;
        }
        cout << ans << "\n";
    }
}
