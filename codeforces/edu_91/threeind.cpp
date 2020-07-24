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
        bool found = false;
        int out;
        for(int i=1 ; i<n-1 ; i++){
            if(a[i-1] < a[i] && a[i] > a[i+1]){
                found = true;
                out = i;
                break;
            }
        }
        if(found)
            cout << "YES\n" << out << " " << out+1 << " " << out+2 << "\n";
        else
            cout  << "NO\n";
    }
}
