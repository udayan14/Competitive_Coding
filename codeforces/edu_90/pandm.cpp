#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        long long int n = s.length();
        long long int m[n+1];
        memset(m,-1,sizeof(m));
        long long int diff = 0;
        for(int i=0 ; i<s.length() ; i++){
            if(s[i]=='+')
                diff++;
            else
                diff--;
            if(diff<0 && m[-diff]==-1){
                m[-diff] = i;
            }
        }
        long long int out = 0;
        for(int i=0 ; i<n+1 ; i++){
            out += m[i]+1;
        }
        out += n;
        cout << out << "\n";
    }
}
