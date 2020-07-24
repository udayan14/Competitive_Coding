#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

long long int mod = 1000000007;

long long int inv(long long int n){
    long long int out = 1;
    for(long long int p = mod-2 ; p>0 ; p = p>>1){
        if((p&1)==1)
            out = (out*n)%mod;
        n = (n*n)%mod;
    }
    return out;
}

long long int inv6 = inv(6);

long long int power_solve(int power , long long int max){
    long long int out = 0;
    for(int base = 2 ; ; base++){
        long long int acc = 1;
        for(int i=0 ; i<power ; i++){
            acc *= base;
            if(acc>max){
                acc = max+1;
                break;
            }
        }
        if(acc > max)
            break;
        out += (max - max%acc) % mod;
        if(out > mod)
            out = out%mod;
    }
    //cout << power << "\t" << out << "\n";
    return out;
}

long long int sum_of_squares(long long int n){
    return ((((((n%mod)*(n+1))%mod)*(2*n+1))%mod)*inv6)%mod;
}

long long int solve2(long long int n){
   if(n<4) return 0;
   long long int cur_base = 2;
   long long int out = 0;
   long long int sqrt_n = sqrtl(n);
   while(cur_base*cur_base <= n){
        long long int contribution = n/(cur_base*cur_base);
        long long int en = sqrtl(n/contribution);
        out += ((contribution%mod) * ((sum_of_squares(en) + mod - sum_of_squares(cur_base-1))%mod))%mod;
        cur_base = en+1;
   }
   return out;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        long long int f[61];
        memset(f,0,sizeof(f));
        for(int i=60 ; i>2 ; i--){
            f[i] = power_solve(i,n);
        }
        f[2] = solve2(n);
        for(int i=60 ; i>=2 ; i--){
            for(int j=2*i ; j <=60 ; j+=i){
                f[i] = (f[i] - f[j])%mod;
                if(f[i] < 0) f[i] += mod;
            }
        }
        long long int output = n%mod;
        for(int i=2 ; i<=60 ; i++){
            output += f[i];
            if(output > mod) output = output%mod;
        }
        cout << output << "\n";
    }
}
