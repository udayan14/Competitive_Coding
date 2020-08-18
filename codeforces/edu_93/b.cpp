#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        char prev = '$';
        int count = 0;
        vector<int> count_blocks;
        for(int i=0 ; i<s.length() ; i++){
            if(s[i]!='1' && count==0){
                prev = s[i];
                continue;
            }
            if(s[i]!='1' && count>0){
                count_blocks.push_back(count);
                count = 0;
                prev = s[i];
            }
            else if(s[i]=='1'){
                count++;
                prev = s[i];
            }
        }
        if(count > 0)
            count_blocks.push_back(count);
        sort(count_blocks.begin(),count_blocks.end(),greater<int>());
        int output = 0;
        for(int i=0 ; i<count_blocks.size() ; i++){
            if(i%2==0)
                output += count_blocks[i];
        }
        cout <<  output << "\n";
    }
    return 0;
}

