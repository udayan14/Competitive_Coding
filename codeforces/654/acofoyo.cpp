#include<iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long int a,b,n,m;
        cin >> a >> b >> n >> m;
        if(m+n > a+b){
            cout << "No\n";
            continue;
        }
        if(a>b){
            if(m>b){
                cout << "No\n";
            }
            else{
                cout << "Yes\n";
            }
        }
        else{
            if(m>a){
                cout << "No\n";
            }
            else{
                cout << "Yes\n";
            }
        }
    }
}
