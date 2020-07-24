#include<iostream>
#include<set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        unsigned long long int a[n];
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        if(n>64){
            cout << "NO\n";
            continue;
        }
        set<unsigned long long int> s;
        bool distinct = true;
        for(int i=0 ; i<n ; i++){
            unsigned long long int temp = 0;
            for(int j=i ; j<n ; j++){
                temp |= a[j]; 
                if(s.count(temp)){
                    distinct = false;
                    break;
                }
                s.insert(temp);
            }
            if(!distinct) break;
        }
        if(distinct) cout << "YES\n";
        else cout << "NO\n";
    }
}
