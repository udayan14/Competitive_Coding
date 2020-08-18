#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int total_count[n+1];
        int row1_count[n+1];
        int row2_count[n+1];
        memset(total_count,0,sizeof(total_count));
        memset(row1_count,0,sizeof(row1_count));
        memset(row2_count,0,sizeof(row2_count));

        int row1[n+1];
        int row2[n+1];
        for(int i=1 ; i<=n ; i++){
            cin >> row1[i];
            row1_count[row1[i]]++;
            total_count[row1[i]]++;
        }
        for(int i=1 ; i<=n ; i++){
            cin >> row2[i];
            row2_count[row2[i]]++;
            total_count[row2[i]]++;
        }
        bool flag = true;
        for(int i=1 ; i<=n ; i++){
            if(total_count[i]!=2){
                flag = false;
                break;
            }
        }
        if(!flag){
            cout << -1 << "\n";
            continue;
        }
        vector<int> output;



        if(!flag){
            cout << -1 << "\n";
            continue;
        }
        cout << output.size() << "\n";
        for(auto i : output) cout << i << " ";
        cout << "\n";
    }
}
