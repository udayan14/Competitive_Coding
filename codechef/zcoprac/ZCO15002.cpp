#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i=0 ; i<n ; ++i)
        cin >> a[i];
    sort(a,a+n);
    long long output = 0;
    for(int i=0 ; i<n ; ++i){
        output += distance(lower_bound(a,a+n,a[i]+k),a+n);
    }
    cout << output << "\n";
}
