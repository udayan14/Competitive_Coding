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

        long long int output = 0;
        for(int i=1 ; i<n ; i++){
            if(a[i]<a[i-1]) output += a[i-1] - a[i];
        }
        cout << output << "\n";
    }
    return 0;
}

