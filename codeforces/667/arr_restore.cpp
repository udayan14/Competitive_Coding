//#define _GLIBCXX_DEBUG

#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        long long int a,b,x,y,n;
        cin >> a >> b >> x >> y >> n;
        while(n){
            if(a > b && b > y){
                b--;
                n--;
            }
            else if(b > a && a > x){
                a--;
                n--;
            }
            else if(a==b && (a > x)){
                a--;
                n--;
            }
            else if(a==b && (b > y)){
                b--;
                n--;
            }
            else if(a==x && b==y)
                break;
        }
        cout << a * b << "\n";
    }
    return 0;
}

