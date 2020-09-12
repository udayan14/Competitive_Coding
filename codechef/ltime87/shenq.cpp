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
        vector<int> temp;
        while(true){
            if(a.size()==1) break;
            int start = 0;
            if(a.size()%2==1){
                start++;
                temp.push_back(a[0]);
            }
            for(int i=start ; i+1<n ; i+=2){
                temp.push_back(a[i] + a[i+1]);
            }
            a = temp;
            temp.clear();
        }
        cout << a.size() << "\n";
        for(auto e : a) cout << e << " ";
        cout << "\n";
    }
    return 0;
}

