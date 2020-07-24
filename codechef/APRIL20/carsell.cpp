#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    long long int p = 1000000007;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0 ; i<n ; ++i)
            cin >> a[i];
        sort(a,a+n);
        long long output = 0;
        for(int i=0 ; i<n ; ++i){
            if(a[n-i-1]-i > 0)
                output = (output + a[n-i-1] - i) %p;
        }
        cout << output << "\n";
    }
}
