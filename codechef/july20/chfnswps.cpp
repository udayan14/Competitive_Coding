#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cassert>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<long long int,int> A_count,B_count,total_count;
        long long int in;
        for(int i=0 ; i<n ; i++){
            cin >> in;
            total_count[in]++;
            A_count[in]++;
        }
        for(int i=0 ; i<n ; i++){
            cin >> in;
            total_count[in]++;
            B_count[in]++;
        }
        bool flag = true;
        vector<long long int> pos_a;
        vector<long long int> pos_b;
        for(const auto &kv: total_count){
            if(kv.second%2==1){
                flag = false;
                break;
            }
            else{
                int temp_a = A_count[kv.first] - kv.second/2;
                if(temp_a > 0){
                    while(temp_a--){
                        pos_a.push_back(kv.first);
                    }
                }
                int temp_b = B_count[kv.first] - kv.second/2;
                if(temp_b>0){
                    while(temp_b--){
                        pos_b.push_back(kv.first);
                    }
                }
            }
        }
        if(!flag) cout << -1 << "\n";
        else{
            long long int output = 0;
            sort(pos_a.begin(),pos_a.end());
            sort(pos_b.begin(),pos_b.end());
            int len = pos_a.size();
            assert(pos_a.size()==pos_b.size());
            for(int i=0 ; i<len ; i++){
                output += min(pos_a[i],pos_b[len-i-1]);
            }
            cout << output << "\n";
        }
    }
}
