#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define mod 1000000000
#define size 100000000
int factorial_arr[size];

void init(){
    memset(factorial_arr,0,sizeof(factorial_arr));
    factorial_arr[0] = 1;
    for(long long int i=1 ; i<size ; i++){
        factorial_arr[i] = (i%mod*factorial_arr[i-1]%mod)%mod;
    }
}

int factorial(int n){
    if(n < size)
        return factorial_arr[n];
    else{
        long long int out = factorial_arr[size-1];
        for(int i=size ; i<=n ; i++){
            out = (out%mod * i%mod)%mod;
        }
        return out;
    }
}

int main() {
    init();
    int n, m;
    cin >> n >> m;
    int A[n];
    int fac_A[n];

    for(int i=0 ; i<n ; i++){
        int in;
        cin >> in;
        A[i] = in;
        fac_A[i] = factorial(A[i]);
    }
    while(m--){
        int c,l,r;
        cin >> c >> l >> r;

        if(c==1){
            l--;
            r--;
            for(int i=l ; i<=r ; i++){
                A[i]++;
                fac_A[i] = (fac_A[i]%mod*A[i]%mod)%mod; 
            }
        }
        else if(c==2){
            l--;
            r--;
            int sum = 0;
            for(int i=l ; i<=r ; i++){
                sum = (sum%mod + fac_A[i]%mod)%mod;
            }
            cout << sum << endl;
        }
        else if(c==3){
            l--;
            A[l] = r;
            fac_A[l] = factorial(r);
        }
    }

    
    return 0;
}
