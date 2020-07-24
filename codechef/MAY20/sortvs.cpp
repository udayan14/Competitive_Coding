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
        int a[n+1];
        for(int i=1 ; i<=n ; ++i)
            cin >> a[i];
        for(int i=0 ; i<m ; i++){
            int p,q;
            cin >> p >> q;
        }
        int visited[n+1];
        int count = 0;
        memset(visited,0,sizeof(visited));

        for(int i=1 ; i<n+1 ; ++i){
            if(!visited[i]){
                visited[i] = 1;
                int j = a[i];
                while(!visited[j]){
                    count++;
                    visited[j] = 1;
                    j = a[j];
                }
            }
        }
        cout << count << "\n";
    }
}
