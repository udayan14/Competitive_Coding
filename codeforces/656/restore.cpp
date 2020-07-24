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
        int count[n+1];
        memset(count,0,sizeof(count));
        int output[n];
        int counter=0;
        int in;
        for(int i=0 ; i<2*n ; i++){
            cin >> in;
            if(count[in]==0)
                output[counter++] = in;
            count[in]++;
        }
        for(int i=0 ; i<n ; i++) cout << output[i] << " ";
        cout << "\n";
    }
}
