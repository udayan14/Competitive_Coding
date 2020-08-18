#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long int n,k,l;
        cin >> n >> k >> l;
        vector<int> d(n);
        for(int i=0 ; i<n ; i++)
            cin >> d[i];
        vector<vector<long long int>> blocks;
        bool flag = true;
        vector<long long int> block;
        for(int i=0 ; i<n ; i++){
            if(d[i] > l){
                flag = false;
                break;
            }

            if(d[i] + k <= l){
                if(block.size()==0) continue;
                else{
                    blocks.push_back(block);
                    block.clear();
                }
            }
            else{
                block.push_back(d[i]);
            }
        }
        if(block.size()!=0) blocks.push_back(block);
        if(!flag){
            cout << "No\n";
            continue;
        }
        for(auto block : blocks){
            if(!flag) break;
            long long int max_depth = -1;
            long long int ind = -1;
            for(int i=0 ; i<block.size() ; i++){
                if(block[i] > max_depth){
                    max_depth = block[i];
                    ind = i;
                }
            }
            long long int skip = l-max_depth;
            ind += 2*skip;
            int incr = 1;
            while(ind + 1 < block.size()){
                if(skip==k) incr=-1;
                else if(skip==0) incr = 1;
                skip+=incr;
                ind++;
                if(block[ind]+skip > l){
                    flag = false;
                    break;
                }
            }
        }
        if(flag) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

