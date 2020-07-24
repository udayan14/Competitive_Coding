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
        int a[n];
        int count[1001];
        int visited[1001];
        memset(count,0,sizeof(count));
        memset(visited,0,sizeof(visited));
        int prev=-1;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        bool flag = true;
        for(int i=0 ; i<n ; i++){
            count[a[i]]++;
            if(prev!=a[i]){
                if(visited[a[i]]){
                    flag = false;
                    break;
                }
                prev = a[i];
                visited[a[i]] = 1;
            }
        }
        if(!flag){
            cout << "NO\n";
            continue;
        }
        int set[1001];
        memset(set,0,sizeof(set));

        for(int i=1 ; i<1001 ; i++)
            if(count[i] > 0)
                set[count[i]]++;
        for(int i=1 ; i<1001 ; i++){
            if(set[i]>1){
                flag = false;
                break;
            }
        }

        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}
