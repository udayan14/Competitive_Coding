#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        bool flag = true;
        while(n--){
            int in;
            cin >> in;
            if(in%2==0)
                flag = false;
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}
