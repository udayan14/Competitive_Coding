#include<iostream>
#include<cstring>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[26];
        memset(a,0,sizeof(a));
        char c;
        while(n--){
            cin >> c;
            a[c-'a']++;
        }
        bool flag = true;
        for(int i=0 ; i<26 ; i++){
            if(a[i]%2==1){
                flag = false;
                break;
            }
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}
