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
        vector<int> a(n);
        for(int i=0 ; i<n ; i++) cin >> a[i];
        if(n==1){
            cout << "T\n";
            continue;
        }
        int xor_val = 0;
        for(auto v : a)
            xor_val ^= v;

        if(xor_val==0){
            cout << "HL\n";
        }
        else{
            cout << "T\n";
        }
    }
    return 0;
}

