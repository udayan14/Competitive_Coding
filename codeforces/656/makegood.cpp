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
        int itr = n-1;
        while(itr>0){
            if(a[itr]<=a[itr-1])
                itr--;
            else break;
        }
        while(itr>0){
            if(a[itr]>=a[itr-1])
                itr--;
            else break;
        }
        cout << itr << "\n";
    }
}
