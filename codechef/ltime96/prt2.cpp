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
        long long int n,k;
        cin >> n >> k;
        vector<long long int> a(n);
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        int x,y;
        for(int i=0 ; i<n-1 ; i++){
            cin >> x >> y;
        }
        sort(a.begin(), a.end(), greater<long long int>());
        long long int output;
        if(n==1){
            output = k*a[0];
        }
        else{
            output = a[1] + (k-1) * a[0];
        }
        cout << output << "\n";
    }
    return 0;
}

