//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        unsigned long long int x,y;
        cin >> y >> x;
        unsigned long long int max_val = max(x,y);
        unsigned long long int base = max_val * max_val;
        //cout << base << "\n";
        unsigned long long int output;
        if(max_val & 1){
            if(x==max_val){
                output = base - y + 1;
            }
            else{
                output = base - 2*max_val + 1 + x;
            }
        }
        else{
            if(x==max_val){
                output = base - 2*max_val + 1 + y;
            }
            else{
                output = base - x + 1;
            }
        }

        cout << output << "\n";
    }
    return 0;
}

