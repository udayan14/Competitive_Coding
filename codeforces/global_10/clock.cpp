//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long int n,k;
        cin >> n >> k;
        vector<long long int> a(n);
        for(int i=0 ; i<n ; i++) cin >> a[i];
        long long int curr_max = LLONG_MIN;
        for(int i=0 ; i<n ; i++){
            if(a[i] > curr_max) curr_max = a[i];
        }
        for(int i=0 ; i<n ; i++){
            a[i] = curr_max - a[i];
        }
        k--;

        if(k%2==1){
            long long int curr_max = LLONG_MIN;
            for(int i=0 ; i<n ; i++){
                if(a[i] > curr_max) curr_max = a[i];
            }
            for(int i=0 ; i<n ; i++){
                a[i] = curr_max - a[i];
            }
        }

        for(auto ele : a) cout << ele << " ";
        cout << "\n";
    }
    return 0;
}

