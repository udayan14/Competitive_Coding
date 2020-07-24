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
        long long int x_out = 0;
        long long int y_out = 0;
        for(int i=0 ; i<4*n-1 ; i++){
            long long int x,y;
            cin >> x >> y;
            x_out ^= x;
            y_out ^= y;
        }
        cout << x_out << " " << y_out << "\n";
    }
}
