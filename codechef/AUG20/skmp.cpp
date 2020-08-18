#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s, p;
        cin >> s >> p;
        vector<int> count(26,0);
        for(int i=0 ; i<s.length() ; i++){
            count[s[i]-'a']++;
        }
        for(int i=0 ; i<p.length() ; i++){
            count[p[i]-'a']--;
        }
        bool first;
        for(int i=0 ; i<p.length() ; i++){
            if(p[i] > p[0]){
                first = false;
                break;
            }
            else if(p[i] < p[0]){
                first = true;
                break;
            }
        }
        for(char i='a' ; i<='z' ; i++){
            if(i==p[0]){
                if(first){
                    cout << p;
                    while(count[i-'a']--) cout << i;
                }
                else{
                    while(count[i-'a']--) cout << i;
                    cout << p;
                }
            }
            else{
                while(count[i-'a']--)
                    cout << i;
            }

        }
        cout << "\n";
    }
    return 0;
}

