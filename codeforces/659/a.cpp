#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;

char invert(char c){
    if(c=='a') return 'b';
    else return 'a';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0 ; i<n ; i++)
            cin >> a[i];
        int max_len = 0;
        for(auto l : a){
            if(l>max_len) max_len = l;
        }
        max_len++;
        string s(max_len,'a');
        cout << s << "\n";
        for(int i=0 ; i<n ; i++){
            for(int j=a[i] ; j<max_len ; j++){
                s[j] = invert(s[j]);
            }
            cout << s << "\n";
        }
    }
    return 0;
}

