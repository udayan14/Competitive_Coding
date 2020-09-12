//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const long long int p = 1000000007;

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

long long int inv(long long int n){
    return mod_exp(n,p-2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<long long int> fact(1000001);
    vector<long long int> inv_fact(1000001);
    fact[0] = 1;
    inv_fact[0] = 1;
    for(int i=1 ; i<1000001 ; i++){
        fact[i] = (fact[i-1] * i) % p;
        inv_fact[i] = inv(fact[i]);
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long int in;
        map<long long int, long long int> m;
        long long int curr_max = 0;
        for(int i=0 ; i<n ; i++){
            cin >> in;
            if(in > curr_max) curr_max = in;
            m[in]++;
        }
        long long int output = mod_exp(2,n);
        bool flag = true;
        long long int subtract = 1;

        if(m[curr_max] & 1){
            flag = false;
        }
        else{
            long long int count = m[curr_max];
            long long int temp = (fact[count] * ((inv_fact[count/2]*inv_fact[count/2]) % p )) % p;
            subtract = (mod_exp(2,n-m[curr_max]) * temp) % p;
        }


        //for(const auto &kvpair : m){
            //auto count = kvpair.second;
            //if(count & 1){
                //flag = false;
                //break;
            //}
            //else{
                //subtract = (subtract * ((fact[count] * ((inv_fact[count/2]*inv_fact[count/2]) % p ) ) % p)) % p;
            //}
        /*}*/
        if(flag){
            output = (output - subtract) % p;
            if(output < 0) output += p;
        }
        cout << output << "\n";
    }
    return 0;
}

