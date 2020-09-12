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
        long long int n;
        cin >> n;
        while(true){
            cout << n << " ";
            if(n==1){
                cout << "\n";
                break;
            }
            if(n&1) n = 3*n + 1;
            else n >>= 1;
        }
    }
    return 0;
}

