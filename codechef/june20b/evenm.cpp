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
        for(int i=0 ; i<n ; i++){
            if((i%2)==0){
                for(int j=1 ; j<=n ; j++){
                    cout << i*n + j << " ";
                }
                cout << "\n";
            }
            else{
                for(int j=0 ; j<n ; j++){
                    cout << (i+1)*n - j << " ";
                }
                cout << "\n";
            }
        }
    }
}
