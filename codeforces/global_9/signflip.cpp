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
        int in;
        for(int i=0 ; i<n ; i++){
            cin >> in;
            if(i&1){
                if(in > 0) in = -in;
            }
            else{
                if(in < 0) in = -in;
            }
            a[i] = in;
        }
        for(int i=0 ; i<n ; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
}
