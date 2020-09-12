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
        long long int sum = 0;
        long long int in;
        for(int i=0 ; i<n-1 ; i++){
            cin >> in;
            sum += in;
        }
        cout << n*(n+1)/2 - sum << "\n";
    }
    return 0;
}

