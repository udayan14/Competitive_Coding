#include<iostream>
#include<set>
#include<map>
#include<deque>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        char a[n];
        char b[n];
        set<char> a_s;
        set<char> b_s;
        map<char,set<int>> a_m;
        map<char,set<int>> b_m;
        deque<set<int> > out;
        bool flag = true;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
            a_s.insert(a[i]);
            a_m[a[i]].insert(i);
        }
        for(int i=0 ; i<n ; i++){
            cin >> b[i];
            if (a[i]!=b[i])
                b_s.insert(b[i]);
            b_m[b[i]].insert(i);
        }
        for(int i=0 ; i<n ; i++){
            if(a[i]<b[i]){
                flag = false;
                break;
            }
        }
        for(const auto &c : b_s){
            if(a_s.count(c))
                continue;
            else{
                flag = false;
                break;
            }
        }
        if(flag){
            cout << b_s.size() << "\n";
            for(auto rit = b_s.crbegin() ; rit!=b_s.crend() ; ++rit){
                set<int> s = b_m[*rit];
                s.insert(*(a_m[*rit].cbegin()));
                cout << s.size() << " ";
                for(const auto &e : s)
                    cout << e << " ";
                cout << "\n";
            }
        }

        else cout << "-1\n";

    }
}
