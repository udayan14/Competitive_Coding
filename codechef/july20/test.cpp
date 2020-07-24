#include<iostream>

using namespace std;

int main(){
    long long int in;
    long long int res = 0;
    while(true){
        cin >> in;
        res ^= in;
        cout << res << "\n";
    }
}
