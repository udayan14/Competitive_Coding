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
        long long int a, b;
        cin >> a >> b;
        long long int min_moves = (b-a)/10;
        if(min_moves < 0) min_moves *= -1;
        int diff = a-b;
        if(diff < 0) diff *= -1;
        if(diff%10) min_moves++;
        cout << min_moves << "\n";
    }
    return 0;
}

