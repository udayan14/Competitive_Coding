#include<iostream>
#include<cstring>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n >> m >> k;
        int C[n][k];
        for(int i=0 ; i<n ; ++i){
            for(int j=0 ; j<k ; ++j){
                cin >> C[i][j];
            }
        }
        for(int i=0 ; i<n ; ++i){
            int freq[m+1];
            memset(freq,0,sizeof(freq));
            for(int j=0 ; j<k ; ++j)
                freq[C[i][j]]++;

            int max_ind = -1;
            int max_val = freq[0];
            for(int i=1 ; i<m+1 ; ++i){
                if(freq[i] > max_val){
                    max_val = freq[i];
                    max_ind = i;
                }
            }      
            cout << max_ind << "\n";
        }
    }
}
