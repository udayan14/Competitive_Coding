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
        vector<int> a(n);
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        vector<int> blocks;
        int count = 0;
        for(int i=0 ; i<n ; i++){
            if(a[i]==0) count++;
            else{
                if(count){
                    blocks.push_back(count);
                    count = 0;
                }
            }
        }
        sort(blocks.begin(),blocks.end(),greater<int>());
        bool flag = true;
        if (blocks.size()==0) flag = false;
        else if(blocks.size()==1){
            if(blocks[0]%2==0)
                flag = false;
        }
        else{
            if(blocks[0]/2 + blocks[0]%2 <= blocks[1])
                flag = false;
            if(blocks[0]%2==0)
                flag = false;
        }
        if(flag) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

