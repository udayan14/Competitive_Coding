//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    cout << setprecision(8);
    while(t--){
        int n,d;
        cin >> n >> d;
        vector<long long int> c(n);
        for(int i=0 ; i<n ; i++) cin >> c[i];
        sort(c.begin(),c.end());
        double first = 0;
        double last = c[1] - c[0] + d;
        double mid;
        while(last-first > 1e-7){
            mid = (first + last) / 2;
            bool flag = true;
            double hit_time = c[0];
            for(int i=1 ; i<n && flag; i++){
                if(hit_time + mid <= c[i] + d){
                    hit_time = hit_time + mid;
                    if(hit_time < c[i]) hit_time = c[i];
                }
                else
                    flag = false;
            }
            if(flag) first = mid;
            else last = mid;
        }
        cout << mid << "\n";
    }
    return 0;
}

