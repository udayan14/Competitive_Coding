#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int x,y,z;
        cin >> x >> y >> z;
        int a,b,c;
        bool flag = false;
        if(x==y && x>=z){
            flag = true;
            a = x;
            b = z;
            c = z;
        }
        else if(y==z && y>=x){
            flag = true;
            c = y;
            a = x;
            b = x;
        }
        else if(x==z && z>=y){
            flag = true;
            b = z;
            a = y;
            c = y;
        }
        if(flag) cout << "YES\n" << a << " " << b << " " << c << "\n";
        else cout << "NO\n";
    }
}
