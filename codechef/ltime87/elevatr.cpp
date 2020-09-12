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
        int n,m;
        cin >> n >> m;
        vector<int> b(n);
        for(int i=0 ; i<n ; i++) cin >> b[i];
        long long int output = 0;
        int first = n;
        for(int i=0 ; i<n ; i++)
            if(b[i]!=-1){
                first = i;
                break;
            }

    }
    return 0;
}

