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
        int n;
        cin >> n;
        vector<int> a(101,0);
        int in;
        for(int i=0 ; i<n ; i++){
            cin >> in;
            a[in]++;
        }
        //for(int i=0 ; i<5 ; i++) cout << a[i] << " ";
        int output = 0;
        int out1 = 0;
        int out2 = 0;
        bool flag = true;
        for(int i=0 ; i<101 ; i++){
            if(a[i] > 1){
                out1++;
                if(flag) out2++;
            }
            else if(a[i] == 1){
                flag = false;
                out1++;
            }
            else{
                break;
            }
        }
        cout << out1 + out2 << "\n";
    }
    return 0;
}

