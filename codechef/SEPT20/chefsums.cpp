//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;


const long long int p = 1000000007;
long long int n,k,m,x;
long long int answer = 0;

vector<long long int> a;

vector<short> is_prime(1000001,1);
vector<long long int> spd(1000001);

void sieve_of_eratosthenes(){
    is_prime[0] = 0;
    is_prime[1] = 0;
    for(int i=2 ; i<1000001 ; i++){
        if(is_prime[i]==1){
            spd[i] = i;
            for(int j=2*i ; j<1000001 ; j+=i){
                if(is_prime[j]) spd[j] = i;
                is_prime[j] = 0;
            }
        }
    }
}

long long int mod_exp(long long int x, long long int y){
    if(x==1) return 1;
    long long int res = 1;
    while(y){
        if(y&1) res = (res*x) % p;
        x = (x*x) % p;
        y >>= 1;
    }
    return res;
}

long long int gcd(long long int m, long long int n){
    if(n==0) return m;
    return gcd(n,m%n);
}

void solve(long long int curr_k, long long int sum, long long int prod, long long int gcd_val, long long int spd_val){
    if(curr_k == k){
        for(auto e : a){
            solve(curr_k-1,mod_exp(e,x),e,e,spd[e]);
        }
    }
    else if(curr_k == 0){
        long long int temp =  (((((gcd_val * sum) % p) * mod_exp(prod,m)) % p) * spd_val) % p;
        answer = (answer + temp) % p;
    }
    else{
        for(auto e : a){
            solve(curr_k-1,(sum + mod_exp(e,x))%p, (prod*e)%p, gcd(e,gcd_val),min(spd[e],spd_val));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve_of_eratosthenes();
    int t;
    t = 1;
    while(t--){
        cin >> n >> k >> m >> x;
        a = vector<long long int> (n);
        for(int i=0 ; i<n ; i++) cin >> a[i];
        solve(k,-1,-1,-1,-1);
        cout << answer << "\n";
    }
    return 0;
}

