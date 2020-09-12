//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<int> &a, int first, int last){
    if(first > last) return 0;

    int baseline = max(a[first-1],a[last+1]);
    int ind = distance(a.begin(), min_element(a.begin() + first, a.begin() + last + 1));
    int min_val = a[ind];
    return min(last-first+1, solve(a,first,ind-1) + solve(a,ind+1,last) + min_val - baseline);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n+2,0);
        for(int i=1 ; i<=n ; i++) cin >> a[i];
        cout << solve(a,1,n) << "\n";
    }
    return 0;
}

