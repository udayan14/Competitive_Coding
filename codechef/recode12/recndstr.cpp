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
        if(len==1){
            cout << "YES\n";
            continue;
        }
        int i=1;
        int j = len-1;
        bool flag = true;
        for(int count = 0 ; count < len ; count ++){
            if(s[i]!=s[j]){
                flag = false;
                break;
            }
            i++;
            j++;
            if(i>=len) i-=len;
            if(j>=len) j-=len;
        }
        if(flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
