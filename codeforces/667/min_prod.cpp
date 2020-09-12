//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

long long int solve(long long int a, long long int b, long long int x, long long int y, long long int n){
    long long int out1;
    if(a-x >= n){
        out1 = (a-n) * b;
    }
    else{
        n -= (a-x);
        a = x;
    
        if(b-y >= n){
            out1 = a * (b-n);
        }
        else{
            n -= (b-y);
            b = y;
            out1 =  a * b ;
        }
    }
    return out1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long int a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        long long int temp_a = a;
        long long int temp_b = b;
        long long int temp_n = n;
        long long int out1 = 0;
        long long int out2 = 0;
        //cout << a << b << x << y << n << "\n";
        cout << min(solve(a,b,x,y,n),solve(b,a,y,x,n)) << "\n";
    }
    return 0;
}

