#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;

long long int msb(long long int n){
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n |= n >> 32;
    n++;
    return (n>>1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long int> a(n);
        long long int or_all = 0;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
            or_all |= a[i];
        }

        int msb_num = msb(or_all);
        while(msb_num!=0){
            
        }
        int count = 0;
        for(auto num : a){
            if(msb_num&num) count++;
        }
        if(count%4==1)
            cout << "WIN\n";
        else cout << "LOSE\n";
    }
    return 0;
}

