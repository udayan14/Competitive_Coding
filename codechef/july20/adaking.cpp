#include<iostream>
#include<cstring>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int k;
        cin >> k;
        char out[8][8];
        int count = 0;
        memset(out,'X',sizeof(out));
        out[0][0] = 'O';
        count++;
        for(int i=0 ; i<8 ; i++){
            for(int j=0 ; j<8 ; j++){
                if(i==0 && j==0) continue;
                if(count==k) break;
                out[i][j] = '.';
                count++;
            }
        }
        for(int i=0 ; i<8 ; i++){
            for(int j=0 ; j<8 ; j++){
                cout << out[i][j];
            }
            cout << "\n";
        }
    }
}
