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
        vector<vector<int>> a(n,vector<int>(n));
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                cin >> a[i][j];
            }
        }
        vector<int> correct(n,0);
        bool all_ones = true;
        for(int i=0 ; i<n ; i++){
            if(a[0][i]==i+1) correct[i] = 1;
            else all_ones = false;
        }
        int num_changes = 0;
        int curr = correct[1];
        for(int i=2 ; i<n ; i++){
            if(correct[i]==curr) continue;
            curr = correct[i];
            num_changes++;
        }
        int out = 0;
        if(all_ones) out = 0;
        else{
            if(correct[n-1]==1){
                out = num_changes;
            }
            else{
                out = num_changes + 1;
            }
        }
        cout << out << "\n";
    }
    return 0;
}

