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
        bool found = false;
        int dist = 0;
        for(int i=0 ; i<n ; ++i){
            int in;
            cin >> in;
            if(!found && in){
                found = true;
                dist = 0;
            }
            else if(in){
                if(dist+1 < 6)
                    flag = false;
                dist = 0;
            }
            else{
                dist++;
            }
        }
        if(flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
