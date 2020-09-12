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
        int x,y;
        for(int i=0 ; i<n ; i++){
            cin >> x >> y;
        }
        long long int output = n;
        while(true){
            if(n<6) break;
            output += n/2;
            n >>= 1;
        }
        cout << output << "\n";
    }
    return 0;
}

