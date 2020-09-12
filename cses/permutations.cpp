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
    t = 1;
    while(t--){
        int n;
        cin >> n;
        if(n==1){
            cout << n << "\n";
            continue;
        }
        else if(n==4) {
            cout << "2 4 1 3\n";
        }
        else if (n<5){
            cout << "NO SOLUTION\n";
            continue;
        }
        else{
            int temp = n;
            while(temp > 0){
                cout << temp << " ";
                temp -= 2;
            }
            temp = n-1;
            while(temp > 0){
                cout << temp << " ";
                temp -= 2;
            }
            cout << "\n";
        }
    }
    return 0;
}

