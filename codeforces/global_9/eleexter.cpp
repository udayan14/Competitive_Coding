#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0 ; i<n ; i++)
            cin >> a[i];
        if(a[0] > a[n-1])
            cout << "NO\n";
        else cout << "YES\n";
    }
}
