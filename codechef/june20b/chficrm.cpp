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
        int c5,c10,c15;
        c5 = c10 = c15 = 0;
        bool flag = true;
        int in;
        for(int i=0 ; i<n ; i++){
            cin >> in;
            if(in==5)
                c5++;
            else if(in==10){
                if(c5>0){
                    c10++;
                    c5--;
                }
                else flag = false;
            }
            else{
                if(c10>0){
                    c15++;
                    c10--;
                }
                else if(c5>1){
                    c15++;
                    c5-=2;
                }
                else flag = false;
            }
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
}
