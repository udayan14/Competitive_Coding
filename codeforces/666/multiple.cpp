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
    int t;
    t = 1;
    while(t--){
        int n;
        cin >> n;
        vector<long long int> a(n);
        for(int i=0 ; i<n ; i++) cin >> a[i];
        if(n==1){
            cout << "1 1\n";
            cout << -a[0] << "\n";
            cout << "1 1\n";
            cout << "0\n";
            cout << "1 1\n";
            cout << "0\n";
            continue;
        }
        cout << "1 1\n";
        long long int rem = a[0]%n;
        if(rem < 0) rem+=n;
        a[0] += -rem;
        cout << -rem << "\n";

        cout << "2 " << n << "\n";
        for(int i=1 ; i<n ; i++){
            long long int rem = a[i]%n;
            if(rem<0) rem+=n;
            a[i] += rem*(n-1);
            cout << rem*(n-1) << " ";
        }
        cout << "\n";

        cout << "1 " << n << "\n";
        for(int i=0 ; i<n ; i++){
            cout << -a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

