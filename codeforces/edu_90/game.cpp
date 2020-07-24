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
        int n = s.length();
        int out = 0;
        int i=0;
        while(i+1<s.length()){
            if(s[i]!=s[i+1]){
                out++;
                s = s.substr(0,i) + s.substr(i+2,string::npos);
                //cout << "New string: " << s << "\n";
                i=0;
            }
            else{
                i+=1;
            }
        }
        //cout << "out " << out << "\n";
        if(out%2)
            cout << "DA\n";
        else
            cout << "NET\n";
    }
}
