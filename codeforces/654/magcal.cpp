#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long int n,r;
        cin >> n >> r;
        long long int output = 0;
        if(n>r){
            output = (r*(r+1))/2;
        }
        else{
            output = ((n-1)*n)/2  + 1 ;
        }
        cout << output << "\n";
    }
}
