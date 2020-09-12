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
        long long int output = 0;
        long long int in;
        cin >> in;
        long long int curr_max = in;
        for(int i=0 ; i<n-1 ; i++){
            cin >> in;
            if(in < curr_max) output += curr_max - in;
            else if(in > curr_max) curr_max = in;
        }
        cout <<  output << "\n";
    }
    return 0;
}

