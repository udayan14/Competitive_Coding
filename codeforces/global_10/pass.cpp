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
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long int> a(n);
        for(int i=0 ; i<n ; i++) cin >> a[i];
        bool flag = false;
        for(int i=1 ; i<n && !flag; i++){
            if(a[i]!=a[0])
                flag = true;
        }
        if(flag) cout << 1 << "\n";
        else cout << n << "\n";
    }
    return 0;
}

