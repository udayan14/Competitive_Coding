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
        if(n==1){
            cout << "1\n";
            cout << "1 1\n";
            continue;
        }
        cout << n/2 << "\n";
        if(n%2==0){
            for(int i=1 ; i<=n/2 ; i++){
                cout << "2 " << 2*i-1 << " " << 2*i << "\n"; 
            }
        }
        else{
            cout << "3 1 2 3\n";
            for(int i=2 ; i<=n/2 ; i++){
                cout << "2 " << 2*i << " " << 2*i+1 << "\n";
            }
        }
    }
}
