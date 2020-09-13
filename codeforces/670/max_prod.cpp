//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<long long int> a(n);
        for(int i=0 ; i<n ; i++) cin >> a[i];
        sort(a.begin(),a.end());
        long long int output = LLONG_MIN;
        long long int val1 = a.end()[-1] * a.end()[-2] * a.end()[-3] * a.end()[-4] * a.end()[-5];
        long long int val2 = a.end()[-1] * a.end()[-2] * a.end()[-3] * a.begin()[0] * a.begin()[1];
        long long int val3 = a.end()[-1] * a.begin()[0] * a.begin()[1] * a.begin()[2] * a.begin()[3];

        output = max(output,max(val1,max(val2,val3)));
        cout << output << "\n";



    }
    return 0;
}

