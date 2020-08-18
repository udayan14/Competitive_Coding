#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string a,b;
        cin >> a >> b;
        bool flag = true;
        map<char,set<int>> m;
        for(int i=0 ; i<n ; i++){
            if(a[i] > b[i]){
                flag = false;
            }
            if(a[i]==b[i]) continue;
            m[a[i]].insert(i);
        }
        if(!flag){
            cout << -1 << "\n";
            continue;
        }
        int output = 0;
        for(char c='a' ; c<='t' ; c++){
            if(m[c].size()==0) continue;
            char temp = 'z';
            for(auto ind : m[c]){
                if(b[ind]<temp) temp=b[ind];
            }
            for(auto ind : m[c]){
                if(b[ind]==temp) continue;
                m[temp].insert(ind);
            }
            m[c].clear();
            output++;
        }
        cout << output << "\n";
    }
    return 0;
}

