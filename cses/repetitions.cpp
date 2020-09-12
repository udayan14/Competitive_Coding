//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--){
        string s;
        cin >> s;
        int curr_max = 0;
        int count = 1;
        char prev = s[0];
        for(int i=1 ; i<s.length() ; i++){
            if(s[i]==prev) count++;
            else{
                prev = s[i];
                if(curr_max < count) curr_max = count;
                count = 1;
            }
        }
        if(curr_max < count) curr_max = count;
        cout << curr_max << "\n";
    }
    return 0;
}

