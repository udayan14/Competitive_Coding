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
        int n;
        cin >> n;
        vector<int> count(26,0);
        for(int i=0 ; i<n ; i++){
            string s;
            cin >> s;
            for(int j=0 ; j<s.length() ; j++)
                count[s[j]-'a']++;
        }
        bool flag = true;
        for(int i=0 ; i<26 && flag; i++){
            if(count[i]%n==0){
                continue;
            }
            else flag = false;
        }
        if(flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

