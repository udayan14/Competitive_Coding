//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int x;
        cin >> x;

        int n = (int)s.size();
        vector<short> w(n,-1);
        for(int i=0 ; i<n ; i++){
            if(s[i]=='0'){
                if(i-x>=0) w[i-x] = 0;
                if(i+x<n)  w[i+x] = 0;
            }
        }
        bool flag = true;
        for(int i=0 ; i<n && flag ; i++){
            if(s[i]=='1'){
                if((i-x>=0 && w[i-x]==-1) || (i+x<n && w[i+x]==-1))
                    continue;
                else
                    flag = false;
            }
        }
        if(!flag) cout << -1 << "\n";
        else{
            for(auto e : w) cout << -e;
            cout << "\n";
        }
    }
    return 0;
}

