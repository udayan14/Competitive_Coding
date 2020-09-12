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
        long long int q;
        long long int all_ones = (1<<20)-1;
        long long int ans = 0;
        long long int result, base;
        cout << 1 << " " << all_ones << endl;
        cin >> base;
        if(base==-1) return 0;
        ans =  (n - base)%2;
        if(ans<0) ans+=2;
        //cout << "Answer: " << ans << "\n";            
        //cout << all_ones << "\n";
        for(int i=1 ; i<20 ; i++){
            cout << 1 << " " << (all_ones ^ (1<<i))<< endl;
            cin >> result;
            if(result==-1) return 0;
            long long int parity = (result - base + n * (1<<i)) & (1<<(i+1));
            if(parity) ans |= (1<<i);
            //cout << "Answer: " << ans << "\n";            
        }
        cout << 2 << " " << ans << endl;
        cin >> result;
        if(result==-1) return 0;
    }
    return 0;
}

