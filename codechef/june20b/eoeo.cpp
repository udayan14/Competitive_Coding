#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    long long int in;
    while(t--){
        cin >> in;
        cout << (in/(in&(-in))/2) << "\n";
    }
}
