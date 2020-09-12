//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<int> s;
        int in;
        for(int i=0 ; i<n ; i++){
            cin >> in;
            if(in)
                s.insert(in);
        }
        cout << s.size() << "\n";
    }
    return 0;
}

