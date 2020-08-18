#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long int l , r;
        cin >> l >> r;
        if(2*l <= r){
            cout << l << " " << 2*l << "\n";
        }
        else
            cout << -1 << " " << -1 << "\n";
    }
    return 0;
}

