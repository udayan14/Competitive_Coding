//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int k;
vector<short> is_reachable;

void solve(long long int n, long long int sum1, long long int sum2){
    if(n==0){
        long long int temp = sum1 - sum2;
        if(temp < 0) temp *= -1;
        if(temp <  is_reachable.size()) is_reachable[temp] = 1;
    }
    else{
        long long int k_power = 1;
        for(int i=0 ; i<k ; i++) k_power *= n;
        solve(n-1,sum1+k_power,sum2);
        solve(n-1,sum1,sum2+k_power);
    }
}

int main(){
    cin >> k;
    
    for(int i= 7 ; i<35 ; i++){
        is_reachable = vector<short> (10000000,0);

        solve(i-1,0,0);
        long long int limit;
        if(k==3){
            limit = i*i*(i+1)*(i+1)/4;
        } 
        

        bool flag = true;
        for(int num = 0 ; num <= limit ; num++){
            if(is_reachable[num] || (num > 0 && is_reachable[num-1]) || (is_reachable[num+1])) continue;
            else{
                flag = false;
                cout << "Number " << num << " unreachable using numbers between 1 and " << i-1 << "\n";
                break;
            }
        }
        if(!flag) continue;

        cout << "All numbers from 1 to " << limit << " are reachable (ans = 0 or 1) using powers from 1 to " << i-1 << "\n";
    }
    return 0;
}

