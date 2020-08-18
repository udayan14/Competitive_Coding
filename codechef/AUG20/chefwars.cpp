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
        long long int h,p;
        cin >> h >> p;
        while(h>0 && p>0){
            h-=p;
            p>>=1;
        }
        if(p==0 && h>0){
            cout << "0\n";
        }
        else{
            cout << "1\n";
        }
    }
    return 0;
}

