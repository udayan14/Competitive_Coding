#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;

long long int num_digits(long long int n){
    if(n%9==0) return n/9;
    else return n/9 + 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long int pc, pr;
        cin >> pc >> pr;
        long long int count_c = num_digits(pc);
        long long int count_r = num_digits(pr);
        if(count_c < count_r){
            cout << "0 ";
            cout << count_c << "\n";
        }
        else{
            cout << "1 ";
            cout << count_r << "\n";
        }
    }
    return 0;
}

