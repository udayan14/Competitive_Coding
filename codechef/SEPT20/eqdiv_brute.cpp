//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<short> group;
vector<short> current_vec;

int k;

long long int ans = LLONG_MAX;

void solve(long long int n, long long int sum1, long long int sum2){
    if(n==0){
        long long int temp = sum1 - sum2;
        if(temp < 0) temp *= -1;
        if(temp < ans){
            ans = temp;
            group = current_vec;
        }
    }
    else{
        long long int k_power = 1;
        for(int i=0 ; i<k ; i++) k_power *= n;
        current_vec.push_back(0);
        solve(n-1,sum1+k_power,sum2);
        current_vec.pop_back();
        current_vec.push_back(1);
        solve(n-1,sum1,sum2+k_power);
        current_vec.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        group = vector<short> (n+1,0);
        current_vec.clear();
        ans = LLONG_MAX;

        solve(n,0,0);
        reverse(group.begin(),group.end());

        cout << ans << "\n";
        for(auto e : group) cout << e;
        cout << "\n";

    }
    return 0;
}

