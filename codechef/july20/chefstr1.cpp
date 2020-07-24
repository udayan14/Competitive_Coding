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
        int prev;
        cin >> prev;
        long long int output = 0;
        for(int i=1 ; i<n ; i++){
            int in;
            cin >> in;
            if(in > prev) output += in-prev-1;
            else output += prev-in-1;
            prev = in;
        }
        cout << output << "\n";
    }
}
