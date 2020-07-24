#include<iostream>
#include<cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int out[n][n];
        int f_val = 2;
        if(k%n==0) f_val = 0;
        memset(out,0,sizeof(out));
        for(int diag = 0 ; diag<n ; diag++){
            if (k==0) break; 
            for(int itr=0 ; itr<n-diag ; itr++){
                if(k==0) break;
                out[itr][itr+diag] = 1;
                k--;
            }
            for(int itr=0 ; itr<diag ; itr++){
                if(k==0) break;
                out[n-1-itr][diag-itr-1] = 1;
                k--;
            }
        }
        cout << f_val << "\n";
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                cout << out[i][j];
            }
            cout << "\n";
        }
    }
}
