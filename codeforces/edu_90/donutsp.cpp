#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long int a,b,c;
        cin >> a >> b >> c;
        long long int out1,out2;
        out1 = -1;
        out2 = -1;
        if(a<c){
            out1 = 1;
        }
        if(a*b>c){
            out2 = b;
        }
        cout << out1 << " " << out2 << "\n";
    }
}
