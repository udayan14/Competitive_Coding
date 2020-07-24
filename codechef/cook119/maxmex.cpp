#include<iostream>
#include<cstring>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int exists[m];
        memset(exists,0,sizeof(exists));
        int in;
        int output = 0;
        for(int i=0 ; i<n ; i++){
            cin >> in;
            if(in<m)
                exists[in] = 1;
            if(in!=m) output++;
        }
        bool flag = true;
        for(int i=1 ; i<m ; i++){
            if(exists[i]==0){
                flag = false;
                break;
            }
        }
        if(flag) cout << output << "\n";
        else cout << "-1\n";
    }
}
