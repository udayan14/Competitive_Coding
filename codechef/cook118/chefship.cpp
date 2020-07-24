#include<iostream>
#include<string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int len = s.length();
        bool allequal = true;
        for(int i=1 ; i<len ; i++){
            if(s[0]!=s[i]){
                allequal = false;
                break;
            }
        }
        if(allequal){
            cout << len/2 - 1 << "\n";
            continue;
        }
        int out = 0;

        for(int i=1 ; i<len/2 ; i++){
            bool flag = true;
            for(int j=0 ; j<i ; j++){
                if(s[j]!=s[i+j]){
                    flag = false;
                    break;
                }
            }
            if(!flag) continue;

            for(int j=0 ; j<len/2 - i ; j++){
                if(s[2*i+j]!=s[i + j + len/2]){
                    flag = false;
                    break;
                }
            }
            if(!flag) continue;
            else out++;
        }
        cout << out << "\n";
    }
}
