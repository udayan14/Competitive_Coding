#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        if((n&(n-1)) == 0){
            cout << -1 << "\n";
            continue;
        }
        long long int output = 0;
        long long int mult = 1;
        long long int temp;
        while(mult < n){
            long long int mult2 = mult<<1;
            long long int qt = n - mult;
            long long  temp = qt/mult2+1;
            output += temp*(mult);
            //cout << "found: " << temp << " " << mult << "\n";
            mult = mult2;
        }
        cout << output-1 << "\n";
    }
}
