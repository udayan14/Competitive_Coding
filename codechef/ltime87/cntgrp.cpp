//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const long long int p = 1000000007;

long long int mod_exp(long long int x, long long int y){
    if(y==0) return 1;
    long long int res = 1;
    while(y){
        if(y&1) res = (res*x)%p;
        y >>= 1;
        x = (x*x)%p;
    }
    return res;
    
}

long long int inv(long long int n){
    return mod_exp(n,p-2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<int> a(n-1);
        vector<long long int> count(n,0);
        for(int i=0 ; i<n-1 ; i++){
            cin >> a[i];
            count[a[i]]++;
        }
        long long int output = 1;
        for(int i=2 ; i<n && output > 0; i++){
            output = (output * mod_exp(count[i-1],count[i])) %p;
        }

        if(output == 0){
            cout << output << "\n";
            continue;
        }
        long long int excess = m - (n-1);
        long long int holes = 0;
        for(int i=1 ; i<n ; i++){
            holes += (count[i]*(count[i]-1))/2;
        }
        if(excess > holes){
            cout << "0\n";
            continue;
        }
        long long int temp = 1;
        for(int i=0 ; i<excess ; i++){
            temp = (temp*(holes-i))%p;
            temp = (temp*inv(i+1))%p;
        }
        output = (output * temp) %p;
        cout << output << "\n";
    }
    return 0;
}

