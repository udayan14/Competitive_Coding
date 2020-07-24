#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long int n, x;
        cin >> n >> x;
        vector<long long int> a(n);
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        auto it = lower_bound(a.begin(),a.end(),x);
        if(it!=a.begin() and (*(it-1)<<1) >= x){
            x = *(it-1) << 1;
            while(it != a.end() && x >= *it){
                x = *it << 1;
                ++it;
            }
        }
        long long int output = distance(a.begin(),it);
        while(it != a.end()){
            long long int val = *it;
            while(x<val){
                x <<= 1;
                output++;
            }
            x = (val<<1);
            output++;
            ++it;
        }
        cout << output << "\n";
    }
}
