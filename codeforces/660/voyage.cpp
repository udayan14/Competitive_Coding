#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> out(n,9);
        int replace;
        if(n%4==0)
            replace = n/4;
        else{
            replace = n/4+1;
        }
        for(int i=0 ; i<replace ; i++){
            out[n-i-1] = 8;
        }
        for(auto e : out)
            cout << e;
        cout << "\n";
    }
    return 0;
}

