#include<iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n ;
        if(n%2) cout << n/2+1 << "\n";
        else cout << n/2 << "\n";
    }
}


