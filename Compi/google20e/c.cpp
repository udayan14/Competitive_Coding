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
        int n;
        cin >> n;
        vector<long long int> e(n);
        vector<long long int> r(n);
        long long int sum = 0;
        for(int i=0 ; i<n ; i++){
            cin >> e[i] >> r[i];
            sum += e[i];
        }
        bool flag = true;
        vector<short> remove(n,0);
        int out = 0;
        while(flag){
            flag = false;
            for(int i=0 ; i<n ; i++){
                if(remove[i]==1) continue;
                if(r[i] + e[i] > sum){
                    remove[i] = 1;
                    out++;
                    sum -= e[i];
                    flag = true;
                }
            }
        }
        if(out<n){
            cout << "Case #" << cas << ": " << out << " " << "INDEFINITELY\n";
            continue;
        }
        long long int curr_max = 0;
        long long int curr_count = -1;
        for(int bit=1 ; bit <(1<<n) ; bit++){
            long long int sum = 0;
            for(int i=0 ; i<n ; i++){
                if(bit & (1<<i)) sum+=e[i];
            }
            long long int temp = 0;
            for(int i=0 ; i<n ; i++){
                if(bit & (1<<i)){
                    if(e[i]+r[i] > sum){
                        if(temp + sum > curr_max || (temp+sum==curr_max && __builtin_popcount(bit) > curr_count)){
                            curr_max = temp + sum;
                            curr_count = __builtin_popcount(bit);
                        }
                        break;
                    }
                    else{
                        temp += e[i];
                    }
                }
            }
        }
        cout << "Case #" << cas << ": " << n - curr_count << " " << curr_max << "\n";
    }
    return 0;
}

