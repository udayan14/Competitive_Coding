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
    for(int cas=1 ; cas<=t ; cas++){
        int n,a,b,c;
        cin >> n >> a >> b >> c;
        int vis_l = a-c;
        int vis_r = b-c;
        int max_val = n;
        int temp = c;
        if(vis_l < 0 || vis_r < 0 || vis_l + vis_r + c > n || c<1){
            cout << "Case #" << cas << ": IMPOSSIBLE\n";
            continue;
        }
        if(vis_l==0 && vis_r==0 && c==1 && c!=n){
            cout << "Case #" << cas << ": IMPOSSIBLE\n";
            continue;
        }
        vector<int> out;
        for(int i=1 ; i<=vis_l ; i++){
            if(vis_l<n-1)
                out.push_back( i + n-vis_l-1);
            else
                out.push_back(i);
        }
        if(vis_l==0 || c>1){
            out.push_back(max_val);
            temp--;
        }

        for(int i=0 ; i<n-(vis_l+vis_r+c) ; i++){
            out.push_back(1);
        }
        if((vis_r==0 && temp > 0) || c>1){
            out.push_back(max_val);
            temp--;
        }
        for(int i=0 ; i<temp ; i++){
            out.push_back(max_val);
        }
        for(int i=1 ; i<=vis_r ; i++){
            out.push_back(max_val-i);
        }
        cout << "Case #" << cas << ": ";
        for(auto el : out) cout << el << " ";
        cout << "\n";
    }
    return 0;
}

