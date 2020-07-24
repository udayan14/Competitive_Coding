#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int in;
        int counter[200001];
        memset(counter,0,sizeof(counter));
        for(int i=0 ; i<n ; i++){
            cin >> in;
            counter[in]++;
        }
        vector<int> lhs;
        vector<int> rhs;
        for(int i=0 ; i<200001 ; i++){
            if(counter[i]){
                lhs.push_back(i);
                counter[i]--;
            }
        }
        for(int i=200000 ; i>0 ; i--){
            if(counter[i]){
                rhs.push_back(i);
                counter[i]--;
            }
        }
        int s1 = lhs.size();
        int s2 = rhs.size();
        int total_size = s1 + s2;
        if(s2>0 && lhs[s1-1]==rhs[0])
            total_size--;

        if(total_size<n){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            for(auto v : lhs)
                cout << v << " ";
            for(auto v : rhs)
                cout << v << " ";
            cout << "\n";
        }
    }
}
