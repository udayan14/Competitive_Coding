#include<iostream>
#include<string>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int len = s.length();
        int out = 0;
        int i=0;
        while(i<len-1){
            if(s[i]!=s[i+1]){
                out++;
                i+=2;
            }
            else i++;
        }
        cout << out << "\n";
    }
}
