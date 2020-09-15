#include<bits/stdc++.h>

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
        for(int i=0 ; i<n ; i++) cin >> a[i];

        vector<int> l(n);
        for(int i=0 ; i<n ; i++) cin >> l[i];

        vector<int> a_unlock;
        for(int i=0 ; i<n ; i++){
            if(l[i]==1) continue;
            a_unlock.push_back(a[i]);
        }
        sort(a_unlock.begin(), a_unlock.end());
        
        int count = a_unlock.size()-1;
        vector<int> temp(n);
        for(int i=0 ; i<n ; i++){
            if(l[i]==1) temp[i] = a[i];
            else{
                temp[i] = a_unlock[count--];
            }
        }

        for(auto e : temp) cout << e << " ";
        cout << "\n";
        continue;

    }
}
