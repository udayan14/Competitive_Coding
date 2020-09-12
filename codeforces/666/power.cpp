//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        int n;
        cin >> n;
        vector<long long int> a(n);
        for(int i=0 ; i<n ; i++) cin >> a[i];
        sort(a.begin(),a.end());
        double last = (double)a[n-1];
        double c = pow(last,1.0/((double)(n-1)));
        long long int lower = floorf(c);
        long long int upper = ceilf(c);
        long long int output = 0;
        long long int temp = 1;
        for(auto v : a){
            long long int add_val = v - temp;
            if(add_val < 0) add_val *= -1;
            output += add_val;
            temp *= lower;
        }
        long long int output2 = 0;
        long long int temp2 = 1;
        for(auto v : a){
            long long int add_val = v - temp2;
            if(add_val < 0) add_val *= -1;
            output2 += add_val;
            temp2 *= upper;
            if(output2 > output) break;
        }
        cout << min(output,output2) << "\n";
    }
    return 0;
}

