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
        vector<long long int> p(n);
        for(int i=0 ; i<n ; i++){
            cin >> p[i];
        }
        sort(p.begin(),p.end(),greater<long long int>());
        long long int output = -1;
        for(auto sq : p){
            if(k%sq==0){
                output = sq;
                break;
            }
        }
        cout << output << "\n";
    }
    return 0;
}

