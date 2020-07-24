#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int output = 0;
        int in;
        for(int i=0 ; i<n ; i++){
            cin >> in;
            if(in > k)  output += in-k;
        }
        cout << output << "\n";
    }
}
