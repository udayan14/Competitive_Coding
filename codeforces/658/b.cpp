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
        bool flag = true;
        if(n==1){
            cout << "First\n";
            continue;
        }
        for(int i=n-2 ; i>=0 ; i--){
            if(a[i]==1)
                flag = !flag;
            else{
                flag = true;
            }
        }
        if(flag) cout << "First\n";
        else cout << "Second\n";
    }
}
